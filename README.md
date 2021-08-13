# uniform_to_laplace

- 설명
c언어를 사용해 uniform distribution random variable을 laplace distribution의 random variable으로 변환하는 코드이다.


- 사용한 수학적인 개념
uniform 분포를 갖는 random variable(X)을 laplace 분포의 cdf의 역함수에 넣으면 laplace 분포를 갖는 random variable(Y)이 생성된다.

  1. 라플라스 분포(y)의 pdf를 범위별로 구분한다. (절대값을 없애기 위해)
  2. 라플라스 분포(y)의 pdf를 적분해 cdf를 구한다.
    2-1. y < μ 일 때의 pdf를 -무한대 ~ y까지 적분한다.
    2-2. y >= μ 일 때의 pdf를 -무한대 ~ y까지 적분한다.
  3. 라플라스 분포(y)의 cdf의 역함수를 구한다.
    3-1. y< μ일 때 역함수를 구하고 ln을 이용해 0<x이라는 범위로 제한한다. -> 0<x<0.5
    3-2. y >= μ일 때 역함수를 구하고 ln을 이용해 x<1이라는 범위로 제한한다. -> 0.5<x<1
  4. 균등 분포(x)를 구한 식(라플라스 분포의 cdf의 역함수)에 대입하면 y로 변환
  
  
  - 결과
  엑셀에 각 값들을 복사 붙여넣기 한 후 그래프를 확인하면 라플라스 분포로 변환된 것을 확인할 수 있다.
  
  - 검증
  matlab을 이용한 k-s검증을 통해 검증할 수 있다.
  
  
