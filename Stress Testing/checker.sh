g++ My_Solution.cpp -o My_Solution
g++ Brute_solution.cpp -o Brute_solution
g++ Test_Generator.cpp -o Test_Generator

for((i = 1; ; ++i)); do
    ./Test_Generator $i > randomInput
    ./My_Solution <randomInput > myOutput
    ./Brute_Solution <randomInput > bruteOutput
    diff -w myOutput bruteOutput || break
    echo "Passed test: "  $i
done

echo -e "\nWA on the following test:"
cat randomInput
echo "Your answer is:"
cat myOutput
echo "Correct answer is:"
cat bruteOutput
