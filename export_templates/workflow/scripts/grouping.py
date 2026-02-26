#!/usr/bin/env python
#
# Script to train a BDT to separate the RDs hadronic signal against all other backgrounds
#

from collections.abc import Iterable


CUTS = { 
    "cut1": 0.75,
    "cut2": 0.35,
    "cut3": 0.5
}

def get_other_categories(templates_config, grouping, all_categories):
    """ Return a list of "others" categories """

    groups = templates_config['templates'][grouping]
    used_categories = []
    for group in groups:
        if isinstance(group, Iterable):
            for c in group:
                used_categories.append(str(c))
        else:
            used_categories.append(str(group))
    others = sorted(set(all_categories) - set(used_categories))
    return others

def get_grouping_info(templates_config, grouping, all_categories):
    """ Return the list of groups for the grouping name specified,
    and the mapping between specific categories and the associated group """
    groups = templates_config['templates'][grouping]
    def group_name(group):
        if isinstance(group, Iterable) and not isinstance(group, str):
            return "_".join([str(c) for c in group])
        else:
            return str(group)

    categ_to_group = {}
    # Iterate on the list of group defines
    others_group_name = None
    for group in groups:
        if isinstance(group, Iterable) and not isinstance(group, str):
            for g in group:
                if g != "others":
                    categ_to_group[str(g)] = group_name(group)
                else:
                    others_group_name = group_name(group)
        else:
            if group != "others":
                categ_to_group[str(group)] = group_name(group)
            else:
                others_group_name = group_name(group)
    others = get_other_categories(templates_config, grouping, all_categories)
    for c in others:
        categ_to_group[c] = others_group_name

    return groups, categ_to_group