#!/usr/bin/env python
import random

# Make enums for callers and basics
class FuncType:
    Caller = 1
    Basic = 2

# Constants for output and general logic
INDENT = '    '
T_SUPPORT = 3
T_CONFIDENCE = 0.65

# Each function is a node, each function call is an edge.
# If caller function calls 4 functions, we've reached max
MAX_BASIC_NODES = 5000
MAX_CALLER_NODES = 15000
MAX_EDGES = 60000

# 2 Types of functions will be generated
#   1) Basic Functions:     These do very simple things and terminate here.
#   2) Caller Functions     These will call many other functions. They are not
#                           expanded when pairing functions; pairing is done by
#                           function names only.

# This function will write any relevant imports required for the code to compile
def printFileHeader():
    print '#include \"stdio.h\"\n'

# Functions to print out the code in the maps
def printFunctionDeclarations( func_map ):
    for func in func_map:
        print 'void ' + func + '(void);'
    if len(func_map) > 0:
        print '\n'

def printBasicFuncDef( func_name ):
    print 'void ' + func_name + '(void) {'
    print INDENT + 'printf(\"Called ' + func_name + '\\n\");'
    print '}\n'

def printCallerFuncDef( func_name, callee_list ):
    print 'void ' + func_name + '(void) {'
    for callee in callee_list:
        print INDENT + callee + '();'
    print '}\n'

def printFunctionDefinitions( func_map ):
    for func in func_map:
        if func_map[func][0] == FuncType.Basic:
            printBasicFuncDef(func);
        elif func_map[func][0] == FuncType.Caller:
            printCallerFuncDef(func, func_map[func][1])

def printMainFunction( func_map ):
    print 'int main() {'

    # print all the caller functions
    for func in func_map:
        if func_map[func][0] == FuncType.Caller:
            print INDENT + func + '();'

    print INDENT + 'return 0;'
    print '}\n'

def printProgram( func_map ):
    printFileHeader()
    printFunctionDeclarations(func_map)
    printFunctionDefinitions(func_map)
    printMainFunction(func_map)

# Each entry in the map will be a tuple that contains:
#   (type(int), functions it calls(list), functions that call it(set))
# These arrays help with preventing infinite recursion

# The second param in the tuple should always be empty. It will not be touched
def addBasicFunc( basic_func_id, func_map ):
    key = "b_" + str(basic_func_id)
    func_map[key] = (FuncType.Basic, [], set())
    return key

def addCallerFunc( caller_func_id, func_map ):
    key = "c_" + str(caller_func_id)
    func_map[key] = (FuncType.Caller, [], set())
    return key

# Register calling relations between functions
def addCallingRelation( caller_func, callee_func, func_map ):
    if (caller_func in func_map) and (callee_func in func_map):
        func_map[caller_func][1].append(callee_func)
        func_map[callee_func][2].add(caller_func)

def getBasicFunc( basic_func_name, func_map ):
    name = 'b_' + str(basic_func_name)
    if (name in func_map) and (func_map[name][0] == FuncType.Basic):
        return func_map[name]
    else:
        return -1

def getCallerFunc( caller_func_name, func_map ):
    name = 'c_' + str(basic_func_name)
    if (name in func_map) and (func_map[name][0] == FuncType.Caller):
        return func_map[name]
    else:
        return -1

# Run the actual script
func_map = {};

for x in xrange(1, MAX_BASIC_NODES + 1):
    addBasicFunc('f' + str(x), func_map)

# TODO: Work on logic for what's being called
calls_per_caller = MAX_EDGES / MAX_CALLER_NODES;
for x in xrange(1, MAX_CALLER_NODES + 1):
    caller_name = 'f' + str(x)
    caller = addCallerFunc(caller_name, func_map)
    for y in xrange(0, calls_per_caller):
        basic_val = x + y
        if basic_val > 5000:
            basic_val = (basic_val % 5000)
        name = 'b_f' + str(basic_val)
        addCallingRelation(caller, name, func_map)

printProgram(func_map)
