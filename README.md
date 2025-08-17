# philosophers
42seoul

![image](https://github.com/Tastypotato245/philosophers/assets/63251068/7463612b-7a9b-4c45-b962-6428b27e2783)


# Philosophers

> 42 Seoul 프로젝트: Dining Philosophers 문제 구현

## 설명
`philosophers` 프로젝트는 **Dining Philosophers Problem**을 C 언어와 Makefile을 사용해 구현한 과제입니다. 여러 철학자가 동시에 식사(resource)를 공유하는 과정에서 발생할 수 있는 **교착 상태(deadlock)**, **기아 상태(starvation)** 등의 동시성 문제를 해결하는 것을 목표로 합니다.

---

## 구현 내용

- **동기화 기법 사용**  
  - `mutex` (또는 `semaphore`)를 활용하여 포크(fork) 자원을 안전하게 공유
  - 교착 상태를 방지하기 위한 기법 (예: 왼손-오른손 순서 고정, 홀짝 전략 등)

- **프로세스 또는 스레드 기반 구현**  
  - 각 철학자 `philosopher`는 독립된 프로세스 또는 스레드로 표현
  - `fork()` 또는 `pthread`를 사용하여 생성

- **행위 시뮬레이션**  
  - `thinking`, `eating`, `sleeping` 등의 상태를 타이밍과 함께 콘솔에 출력
  - 각 상태 전환에 딜레이(delay)를 넣어 시뮬레이션 효과 제공

- **강제 종료 및 종료 조건 처리**  
  - 지정된 횟수 이상 식사 시 또는 철학자 중 한 명이 일정 시간 동안 먹지 못하는 경우 종료
  - `SIGINT` 또는 `SIGTERM` 신호 처리 구현

---

## 요구 사항

- C 컴파일러 (예: `gcc`)
- POSIX 호환 환경 (Linux, macOS 등)
- `Make` 빌드 도구

---

## 설치 및 사용법

```bash
# 리포지토리 복제
git clone https://github.com/Tastypotato245/philosophers.git
cd philosophers

# 빌드
make

# 실행 예시
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_meals]
