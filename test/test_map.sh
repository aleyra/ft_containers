OK='\e[32mOK\e[0m'
KO='\e[31mKO\e[0m'

rm -rf map_results
mkdir -p map_results map_results/logs map_results/diff map_results/build map_results/exe

printf "%s\n" "----------------------------------------------------------------------------"
printf "%s\n" "                                    MAP                                     "
printf "%s\n" "----------------------------------------------------------------------------"
printf "%s\n" " Test Name                       | Build         | Run           | Compare  "
printf "%s\n" "----------------------------------------------------------------------------"
for i in $(ls map)
do
	NAME=$(basename $i .cpp)
	c++ -Wall -Wextra -Werror -g3 map/$i -DUSE_STD -o map_results/exe/$NAME.std
	STD_BUILD_STATUS=$?
	c++ map/$i -I . -I ../includes -g3 -o ./map_results/exe/$NAME.ft 2>map_results/build/$NAME.ft.build
	if [ $? -eq 0 ]
	then
		FT_BUILD_STATUS=$OK
	else
		FT_BUILD_STATUS=$KO
		FT_RUN_STATUS=$KO
		COMPARE_STATUS=$KO
		printf " %-32.32s| %b            | %b            | %b\n" $NAME $FT_BUILD_STATUS $FT_RUN_STATUS $COMPARE_STATUS
		continue
	fi

	./map_results/exe/$(basename $i .cpp).std > ./map_results/logs/$NAME.std.log
	./map_results/exe/$(basename $i .cpp).ft > ./map_results/logs/$NAME.ft.log
	if [ $? -eq 0 ]
	then
		FT_RUN_STATUS=$OK
	else
		FT_RUN_STATUS=$KO
	fi

	diff ./map_results/logs/$NAME.std.log ./map_results/logs/$NAME.ft.log > ./map_results/diff/$NAME.diff
	if [ $? -eq 0 ]
	then
		COMPARE_STATUS=$OK
	else
		COMPARE_STATUS=$KO
		printf " %-32.32s| %b            | %b            | %b\n" $NAME $FT_BUILD_STATUS $FT_RUN_STATUS $COMPARE_STATUS
		continue
	fi

	printf " %-32.32s| %b            | %b            | %b\n" $NAME $FT_BUILD_STATUS $FT_RUN_STATUS $COMPARE_STATUS

	rm -rf ./map_results/diff/$NAME.diff ./map_results/exe/$NAME.ft ./map_results/logs/$NAME.ft.log ./map_results/exe/$NAME.std ./map_results/logs/$NAME.std.log ./map_results/build/$NAME.ft.build
done
