cmake_minimum_required(VERSION 3.12)
project(SecondYearProject-BIU)

set(CMAKE_CXX_STANDARD 11)

add_executable(SecondYearProject_BIU main.cpp Command.h CommandExpression.cpp CommandExpression.h ConnectCommand.cpp ConnectCommand.h DefineVarCommand.cpp DefineVarCommand.h Div.cpp Div.h Expression.h IfCommand.cpp IfCommand.h Minus.cpp Minus.h Mult.cpp Mult.h Number.cpp Number.h OpenServerCommand.cpp OpenServerCommand.h Parser.cpp Parser.h Plus.cpp Plus.h PrintCommand.cpp PrintCommand.h WhileCommand.cpp WhileCommand.h DataReaderServer.cpp DataReaderServer.h ConditionParser.cpp ConditionParser.h Lexer.cpp Lexer.h ShuntingYard.cpp ShuntingYard.h SymbolTable.h BindingTable.h PathsTable.h)
