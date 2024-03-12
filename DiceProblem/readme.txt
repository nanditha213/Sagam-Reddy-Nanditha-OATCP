We start by initializing a vector, dp, with integers to store the number of ways to achieve each sum from 0 to n. Initially, all elements of dp are set to 0. Since there's only one way to get a sum of 0 (by not throwing the dice), we set dp[0] to 1.

Next, we iterate through each possible outcome of throwing a dice (from 1 to 6). For each outcome i, we update the dp vector to count the number of ways to obtain each sum from i to n.

Inside the outer loop, there's an inner loop that goes through the possible sums from i to n. We update dp[j] by adding the number of ways to obtain the sum j - i.

Once all counts are updated, we return the value of dp[n], representing the number of ways to obtain the desired sum n using the outcomes of throwing the dice.

In the main function, we read the number of test cases t. For each test case, we read the target sum sum. If the sum is negative (which is not possible), we print "Not Possible". Otherwise, we compute and print the number of ways to obtain the sum using the countWays function.
