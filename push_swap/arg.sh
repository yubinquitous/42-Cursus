export ARG=$(./random_numbers 500)
echo $ARG
./push_swap $ARG | ./checker $ARG
./push_swap $ARG | wc -l
