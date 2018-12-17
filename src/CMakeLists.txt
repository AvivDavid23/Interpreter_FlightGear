cmake_minimum_required(VERSION 3.12)
project(SecondYearProject-BIU)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS -pthread)

add_executable(SecondYearProject_BIU main.cpp Command.h CommandExpression.cpp CommandExpression.h ConnectCommand.cpp ConnectCommand.h DefineVarCommand.cpp DefineVarCommand.h Div.cpp Div.h Expression.h IfCommand.cpp IfCommand.h Minus.cpp Minus.h Mult.cpp Mult.h Number.cpp Number.h OpenServerCommand.cpp OpenServerCommand.h Parser.cpp Parser.h Plus.cpp Plus.h PrintCommand.cpp PrintCommand.h WhileCommand.cpp WhileCommand.h Shunting-Yard.h DataReaderServer.cpp DataReaderServer.h DataWriterClient.cpp DataWriterClient.h Shunting-Yard.cpp)
