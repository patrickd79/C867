//
//  degree.hpp
//  C867: Class Roster
//
//  Created by PATRICK DENNEY on 9/1/20.
//  Copyright © 2020 PATRICK DENNEY. All rights reserved.
//

#pragma once
#include <stdio.h>
#include <string>
using namespace std;

enum DegreeProgram { SECURITY, NETWORK, SOFTWARE, NONE };
//used to transfer enum values to strings
static const string degreeProgFeed[] = {"SECURITY", "NETWORK", "SOFTWARE", "NONE"};

