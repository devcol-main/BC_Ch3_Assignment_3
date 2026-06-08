# BC_Ch3_Assignment_3

## 3번 과제 필수 & 도전

<br>

<p align="center">
<img src="https://github.com/devcol-main/BC_Ch3_Assignment_3/blob/7aecdab82c5e40155518cf9d3356f0b67aedb245/Record/Record_2026_06_08_10_14_40_200.gif" width="50%" alt="B.C. Ch3 Assignment 3 gif">
</p>

<br> 


## Related Links
- Github (Public): https://github.com/devcol-main/BC_Ch3_Assignment_3
- Google Drive (Share as Commenter) : https://drive.google.com/drive/folders/1UhgaLPygtlhRqmk8DkS9esjAwUtQbaX6?usp=sharing
- YouTube (Unlisted): https://youtu.be/ih6_73y3hsw

## 3번 Assignment

## 1️⃣ Intro : 회전 발판으로 배우는 언리얼 C++의 핵심 구조

- **Tick 함수 활용 :** `DeltaTime`을 활용하여 프레임 독립적인 회전 및 이동 로직 구현
- **동적 Transform 제어 :** `AddActorLocalRotation()`과 위치 변경을 통한 실시간 오브젝트 제어
- **리플렉션 시스템 이해 :** `UPROPERTY`를 활용하여 변수를 에디터에 노출하고 조정하는 방법 학습

- 회전 발판, 이동 플랫폼과 같은 **동적 퍼즐 오브젝트를 C++로 직접 구현**
- 변수 값을 에디터에서 조정하며 **게임플레이를 효율적으로 튜닝**

- 플랫폼, 함정, 트랩, 엘리베이터 등 다양한 **환경 상호작용 오브젝트 제작**에 활용됩니다.

## 2️⃣ 필수 기능

<aside>

---

1. **퍼즐 오브젝트 설계**
    - [x]  스테이지 테마를 본인이 원하는 분위기(SF, 중세, 공장 지형 등)로 자유롭게 설정
    - 장식용 메쉬/라이트 등을 추가하여 분위기를 풍부하게 만들 수도 있습니다.

---

2. **서로 다른 Actor 클래스 2개 이상 구현**
    - [x]  C++ Actor 클래스 최소 2개 생성
    - 각 `StaticMeshComponent` 포함 맵에 배치 가능한 형태여야합니다.
    - 두 클래스는 서로 다른 동작 로직(회전용 / 이동용 등) 수행해야합니다.

---

3. **Tick 함수 기반 동적 Transform 변경**
    
    **회전 기능 (Rotating Actor)**
    
    - [x]  `Tick(float DeltaTime)` 에서 `AddActorLocalRotation()`로 **매 프레임 회전** 적용
    
    **이동 기능 (Moving Platform Actor)**
    
    - [x]  `Tick(float DeltaTime)`에서 위치를 변경하여 **왕복 이동** 구현
    - [x]  `StartLocation`(시작 위치) 저장/기준점으로 사용
    - [x]  `MoveSpeed`(이동 속도) 적용
    - [x]  `MaxRange`(왕복 범위) 기준으로 이동 제한
    
    **프레임 독립성**
    
    - [x]  이동/회전 시 반드시 `DeltaTime` 을 활용
    - 하드웨어 성능에 관계 없이 일정한 움직임을 보장해야합니다.
    - 회전하는 톱니바퀴, 엘리베이터 등으로 자유롭게 확장 가능합니다.

---

4. **리플렉션 적용**
    - [x]  주요 변수 (회전 속도, 이동 속도, 이동 범위 등)를 `UPROPERTY`로 선언하여 **에디터에서 조정**
    - [x]  `EditAnywhere`, `BlueprintReadWrite`, `Category` 등을 활용하여 **Details 패널**에서 편집 가능하게 만들기
    - 플레이 중 Details 패널에서 값 변경 시 **즉시 반영**되는지 확인합니다.
    - C++ 클래스의 자식 블루프린트를 만들어 시각적 효과 등의 추가 로직을 Blueprint에서 구현해도 좋습니다.

---

5. **오브젝트 배치 및 테스트**
    - [x]  레벨에 제작한 회전 발판과 이동 플랫폼을 여러 개 배치
    - [x]  각각 다른 속도, 이동범위, 회전값 적용
    - [x]  플레이 모드에서 오브젝트가 의도대로 움직이는지 확인
    - [x]  속도 변경이 실시간 반영되는지 확인
</aside>

## 3️⃣ 도전 기능 가이드

<aside>

---

1. **타이머 시스템 활용**
    
    **타이머 활용**
    
    - [x]  `FTimerHandle`과 `GetWorld()->GetTimerManager().SetTimer(...)`를 사용해 특정 시간 후 또는 주기적으로 함수를 호출
    - [x]  매 프레임 호출(`Tick`)보다 효율적인 퍼포먼스를 제공
    
    **시간 기반 로직 구현**
    
    - [x]  일정 시간 후 발판이 사라지거나, 주기적으로 다른 위치로 이동하는 로직 추가

---

2. **랜덤 퍼즐 생성**
    
    **동적 스폰**
    
    - [x]  게임 시작 시 `SpawnActor`를 통해 회전 발판/이동 플랫폼을 임의 좌표에 여러 개 배치
    - 참고 : 언리얼 공식 문서 SpawnActor
    - 랜덤 스테이지의 기초 개념을 체험할 수 있습니다.
    
    **랜덤 속성 부여**
    
    - [x]  회전/이동 속도, 이동 범위, 각도 등을 `FMath::RandRange`로 생성하여 매번 다른 퍼즐 코스를 구성
</aside>

## 4️⃣ Goal : 제출 일정

<aside>

### ✅ 제출 일정

---

- **제출 일정** `3~4번과제 동일`
    - 2026-06-18(목) 18:00까지

- **제출해야 할 것**
    - GitHub 링크
    - 구글 드라이브 링크
    - 시연 영상(30초~1분)
        - 맵에 배치된 발판/장애물이 움직이는 모습
        - 에디터 Details 패널에서 변수 값을 변경해 동작이 달라지는 장면
</aside>

## 5️⃣ 평가 **기준**

| 항목 | 점수 | 평가 내용 |
| --- | --- | --- |
| **완성도(필수)** | 50점 | - 서로 다른 C++ Actor 클래스로 구현되었는가?
- Tick 함수에서 DeltaTime을 이용해서 회전, 이동이 구현되었는가?
- Details 패널에서 값 수정 시 게임 내 동작이 즉시 반영되는가? |
| **이해도(필수)** | 30점 | - Tick 함수가 매 프레임마다 호출되며, DeltaTime이 프레임 간 경과 시간을 나타낸다는 점을 정확히 이해하였나?
- 언리얼 엔진의 리플렉션(UPROPERTY, UFUNCTION 등)의 목적과 사용법을 이해하였나? |
| **우수성(도전)** | 20점 | - 타이머 시스템(GetTimerManager().SetTimer(...))을 활용한 시간 기반 로직을 구현했는가?
- 랜덤 스폰을 통해 매번 다른 위치/각도로 퍼즐을 생성하는 로직을 구현했는가? |
