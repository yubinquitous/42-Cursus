export ARG=$(./random_numbers 100 -100)
echo $ARG
./push_swap $ARG | ./checker $ARG
./push_swap $ARG | wc -l
