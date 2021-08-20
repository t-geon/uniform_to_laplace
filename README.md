# uniform_to_laplace

This is the code I wrote through visual studio 2019 on windows.

- Explanation
This code converts a uniform distribution random variable to a laplace distribution random variable.


- mathematical concepts
Putting the uniform distribution random variable(X) into the inverse function of the cdf of the laplace distribution is converted into a laplace distribution random variable(Y).

  1. The pdf of the Laplace distribution (y) is classified according to the range. (remove the absolute value)
  2. Integrate the pdf of the Laplace distribution (y) to obtain the cdf.
    2-1. y < μ) Integrate the pdf from -infinity to y.
    2-2. y >= μ) Integrate the pdf from -infinity to y.
  3. Find the inverse function of the cdf of the Laplace distribution (y).
    3-1. y< μ) Find the inverse function and limit it to the range 0 < x using ln. -> 0<x<0.5
    3-2. y >= μ) Find the inverse function and constrain it to the range x<1 using ln. -> 0.5<x<1
  4. Substitute the uniform distribution (x) into the inverse of the Laplace distribution cdf.
  
  
  - result
   If you check the graph after copying and pasting the values printed in Excel
   you can see that they have been converted to Laplace distribution.
  
 - verification
   It can be verified through k-s verification using matlab.
  
  
