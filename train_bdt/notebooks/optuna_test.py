import optuna
import xgboost as xgb
import sklearn
import numpy as np

data = np.load("bdt_training_data.npz")
Xtrain_scaled = data['Xtrain_scaled']
ytrain = data['ytrain']
Xtest_scaled = data['Xtest_scaled']
ytest = data['ytest']
dtrain = xgb.DMatrix(Xtrain_scaled, label=ytrain)
dvalid = xgb.DMatrix(Xtest_scaled, label=ytest)

def objective(trial):

    param = {
        "verbosity": 0,
        "objective": "binary:logistic",
        # defines booster, gblinear for linear functions.
        "booster": trial.suggest_categorical("booster", ["gbtree", "gblinear", "dart"]),
        # L2 regularization weight.
        "lambda": trial.suggest_float("lambda", 1e-8, 1.0, log=True),
        # L1 regularization weight.
        "alpha": trial.suggest_float("alpha", 1e-8, 1.0, log=True),
        # sampling ratio for training data.
        "subsample": trial.suggest_float("subsample", 0.2, 1.0),
        # sampling according to each tree.
        "colsample_bytree": trial.suggest_float("colsample_bytree", 0.2, 1.0),
        "tree_method": "gpu_hist",
    }

    if param["booster"] in ["gbtree", "dart"]:
        # maximum depth of the tree, signifies complexity of the tree.
        param["max_depth"] = trial.suggest_int("max_depth", 1, 9, step=2)
        # minimum child weight, larger the term more conservative the tree.
        param["min_child_weight"] = trial.suggest_int("min_child_weight", 2, 10)
        param["eta"] = trial.suggest_float("eta", 1e-8, 1.0, log=True)
        # defines how selective algorithm is.
        param["gamma"] = trial.suggest_float("gamma", 1e-8, 1.0, log=True)
        param["grow_policy"] = trial.suggest_categorical("grow_policy", ["depthwise", "lossguide"])

    if param["booster"] == "dart":
        param["sample_type"] = trial.suggest_categorical("sample_type", ["uniform", "weighted"])
        param["normalize_type"] = trial.suggest_categorical("normalize_type", ["tree", "forest"])
        param["rate_drop"] = trial.suggest_float("rate_drop", 1e-8, 1.0, log=True)
        param["skip_drop"] = trial.suggest_float("skip_drop", 1e-8, 1.0, log=True)

    bst = xgb.train(param, dtrain, num_boost_round= trial.suggest_int("num_boost_round", 100, 800))
    yscore = bst.predict(dvalid)
    fpr, tpr, _ = sklearn.metrics.roc_curve(ytest, yscore)
    roc_auc = sklearn.metrics.auc(fpr, tpr)
    print(f"AUC:{roc_auc}")
    return roc_auc


study = optuna.create_study(direction="maximize", study_name="bdt", storage="sqlite:///{}.db".format("BDT"), load_if_exists=True)
study.optimize(objective, n_trials=100)
print(study.best_trial)
