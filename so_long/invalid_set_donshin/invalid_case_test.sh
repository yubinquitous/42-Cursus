echo "Wrong usage1: './so_long'"
./so_long
echo

echo "Wrong usage2: './so_long map/map1.ber map/map2.ber'"
./so_long map/map1.ber map/map2.ber
echo

echo "Not exist file: './so_long map/not_exist_file.ber'"
./so_long map/not_exist_file.ber
echo

echo "Wrong suffix1: './so_long map/wrong_suffix.ver'"
./so_long map/wrong_suffix.ver
echo

echo "Wrong suffix2: './so_long ber'"
./so_long ber
echo

echo "Empty map file: './so_long map/empty_map.ber'"
./so_long map/empty_map.ber
echo

echo "Multiple player spon site(P) exist: './so_long map/multi_P.ber'"
./so_long map/multi_P.ber
echo

echo "Collection(C) is not exist: './so_long map/no_C.ber'"
./so_long map/no_C.ber
echo

echo "Exit(E) is not exist: './so_long map/no_E.ber'"
./so_long map/no_E.ber
echo

echo "Player spon site(P) is not exist: './so_long map/no_P.ber'"
./so_long map/no_P.ber
echo

echo "Map is not rectangle: './so_long map/not_rectangle.ber'"
./so_long map/not_rectangle.ber
echo

echo "Map is not surrounded by walls: './so_long map/not_surrounded.ber'"
./so_long map/not_surrounded.ber
echo

echo "Invalid component is exist: './so_long map/invalid_comp.ber'"
./so_long map/invalid_comp.ber
