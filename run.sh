rm  -rf  a.out  
rm -rf core* 

g++ -std=c++11 -v  chap106.cpp -lpthread 

echo "------------------------------------------"

./a.out 