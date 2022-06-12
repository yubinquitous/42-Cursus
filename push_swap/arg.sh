export ARG=$(./random_numbers 100)
#./push_swap $ARG
echo $ARG
./push_swap $ARG | ./checker $ARG
./push_swap $ARG | wc -l
