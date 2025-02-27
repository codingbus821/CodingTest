# 코드실행 시간을 측정하기 위해서 time이라는 외부라이브러리를 불러옴
import time

# start라는 변수에 코드실행 시작 시각 값 저장
start = time.time()

# 입력받은 값(x)이하의 모든 소수를 반환하는 함수 선언
def prime(x):
    
    # 모든 요소가 True로 구성되며, 입력받은 값(x)을 길이로 하는 배열 생성
    candidate = [True] * x
    
    # x의 최대 약수는 x**0.5 이하의 수이므로, i 를 m까지만 반복하더라도
    # 아래의 배수 제거방법을 통해 소수가 아닌 수를 판별할 수 있음
    m = int(x**0.5)
    for i in range(2, m + 1):
        
        # 배열의 요소의 값이 True인 경우, 그 수가 소수인지 아직 판별이 안되었음을 의미
        # 즉, 아래의 수행문 실행
        if candidate[i] == True:
            
            # 어떤 수의 배수는 소수일 수 없으므로, 
            # 입력받은 값보다 작음과 동시에 candidate[i]에 해당하는 수의 배수는 모두 False로 저장함
            for j in range(i+i, x, i):
                candidate[j] = False
    
    # 앞선 candidate 배열에서, True로 저장된(소수로 판별된) 인덱스들을 담은 새로운 배열을 반환
    # 즉, 이 반환되는 배열이 입력받은 값 x 미만의 소수로 구성된 배열임
    return [i for i in range(2, x) if candidate[i] == True]

# 앞서 선언한 함수 prime에 100을 입력, 함수의 반환 결과를 prime_arr에 저장
prime_arr = prime(99999999)

# prime_arr, 코드실행 시간 출력
# print(prime_arr)
print('Time:', time.time() - start)