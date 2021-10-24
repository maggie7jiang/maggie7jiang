class Solution {
public:
    int fib(int n) {
        if (n == 0)
        {
            return 0;
        }
        if (n == 1)
        {
            return 1;
        }
        return fib(n-1) + fib(n-2);
    }
};

//find this Binet's Nth-term Formula
/*Using Binet's Formula for the Nth Fibonacci involves 
the usage of our golden section number Phi.Phi = ( sqrt(5) + 1 ) / 2 */
//http://www.maths.surrey.ac.uk/hosted-sites/R.Knott/Fibonacci/fibFormula.html#section1
//Time Complexity - O(1)Space Complexity - O(1)

class Solution {
public:
	double phi = (sqrt(5) + 1) / 2;
	return round(pow(phi, n) / sqrt(5));
}
