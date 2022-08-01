OK='\e[32mOK\e[0m'
KO='\e[31mKO\e[0m'

rm -rf vec_results
mkdir -p vec_results vec_results/logs vec_results/diff vec_results/build vec_results/exe

printf "%s\n" "----------------------------------------------------------------------------"
printf "%s\n" "                                   VECTOR                                   "
printf "%s\n" "----------------------------------------------------------------------------"
printf "%s\n" " Test Name                       | Build         | Run           | Compare  "
printf "%s\n" "----------------------------------------------------------------------------"
for i in $(ls vector)
do
	NAME=$(basename $i .cpp)
	c++ -Wall -Wextra -Werror -g3 vector/$i -DUSE_STD -o vec_results/exe/$NAME.std
	STD_BUILD_STATUS=$?
	c++ -g3 vector/$i -I . -I ../includes -o ./vec_results/exe/$NAME.ft 2>vec_results/build/$NAME.ft.build
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

	./vec_results/exe/$(basename $i .cpp).std > ./vec_results/logs/$NAME.std.log
	./vec_results/exe/$(basename $i .cpp).ft > ./vec_results/logs/$NAME.ft.log
	if [ $? -eq 0 ]
	then
		FT_RUN_STATUS=$OK
	else
		FT_RUN_STATUS=$KO
	fi

	diff ./vec_results/logs/$NAME.std.log ./vec_results/logs/$NAME.ft.log > ./vec_results/diff/$NAME.diff
	if [ $? -eq 0 ]
	then
		COMPARE_STATUS=$OK
	else
		COMPARE_STATUS=$KO
		printf " %-32.32s| %b            | %b            | %b\n" $NAME $FT_BUILD_STATUS $FT_RUN_STATUS $COMPARE_STATUS
		continue
	fi

	printf " %-32.32s| %b            | %b            | %b\n" $NAME $FT_BUILD_STATUS $FT_RUN_STATUS $COMPARE_STATUS

	rm -rf ./vec_results/diff/$NAME.diff ./vec_results/exe/$NAME.ft ./vec_results/logs/$NAME.ft.log ./vec_results/exe/$NAME.std ./vec_results/logs/$NAME.std.log ./vec_results/build/$NAME.ft.build
done
