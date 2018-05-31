rm -rf dist
mkdir dist
eosiocpp -o dist/jynxpro.wast jynxpro.cpp
eosiocpp -g dist/jynxpro.abi jynxpro.cpp
