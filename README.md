## ROS 란
ROS 는 "Robot Operating System" 의 약자이지만, 실제로는 운영체제가 아니다.
ROS는 로봇 으용 프로그램의 개발을 쉽게하기 위해 만들어진 소프트웨어 라이브러리 및 도구 셋이다.
일반적으로 사용되는 기능구현, 프로세스간 메세지 통신, 패키지관리를 포함하여 운영체제에서 기대할수있는 서비스를 제공한다.

## ROS 선태해야하는 이유 :
### 1. ROS는 open source 이다
        ROS 는 무료이며 상업적목적으로도 사용할수 있다.
### 2. 로봇의 모든 변환은 ROS 에서 추적된다.
        더이상 엔드 이펙트의 위치를 찾기 위해 forware kinematics 방적식을 찾을 필요가 없다.
        로봇을 설명하는 URDF형식을 제공하기만 하면 된다. tf 도는 tf2 모듈은 베이스에서 엔드 이펙트까지 
        로봇의 모든 변환을 추적한다.
### 3. IK 문제를 해결하는 IK 솔버를 제공한다.
        단순하거니 벅잡한 로봇 조작기에 대한 IK 문제를 해결하는 많은 플로그인이 존재한다.
        따라서 IK에대한 closed form equations 을 찾거나 Jocabian 역행렬을 찾는 시간이 절약된다.
        IK 솔버는 IKfast(Analytical Solver) 및 kdl(Numerical Solver)  이다.
### 4. 경로계획이나 장애물회핑에 대한 솔루션으로 Moveit 패키지를 사용한다.
       Moveit! ROS 에서 모션계획, 조작, 3D 인식, 운동학, 충돌검사, 제어 및 탐색을 
       수행하기 위한 패키지 및 도구 세트 이다.
### 5. 차동 로봇을 구현하는 경우에는   ROS navigation stack을 사용한다.
      ROS 네비게이션 스텍에는 모바일 로봇, 특히 차동 로봇에 바로 사용할수 있는 네비게이션 알고리즘이 포함 되어 있다.
      ROS 네비게이션을 시용하여 로봇이 주어진 환경에서 자율적으로 움직이도록 할수 있다.
### 6. ROS 는 ROS Control 을 사용하여 로봇의 액추에이터를 제어한 쉬운 방법을 제공한다
      ROS Control 은 로봇의 움직임을 빠르고 부드럽게 만들기 위해 joint limits PID 제어 루프를 제공한다.
### 7. Open CV Interfaced to ROS.
      비젼및 인식작업을 위해 OpenCV 라이브러리를 사용한다.
### 8. ROS 에는 로봇을 시각화 및 시뮬레이션을 도와주는 도구를 제공한다
      Gazebo 에서는 모든 물리적 속성(예: 무게, 관성, 충돌 등)을 사용하여 로봇의 정확한 복제본을 만들고  
              실제 하드웨어에서 테스트하기 전에 먼저 시뮬레이션에서 코드를 테스트할 수 있습니다
      Rviz 는 실제/시뮬레이션된 로봇(예: 관절 동작, 비전 등)을 시각화하는 디버깅 도구이다
### 9. ROS 는 라즈베리파이와 같은 임베디드 보드에서 실행할수 있다


## ROS workspace  생성:
ROS 는 catkin 을 사용하여 ROS 프로젝트를 빌드한다. 따라서 먼저 catkin workspace 를 만드어야 한다.
먼저 terminal 에서 다음과같이 작업공간을 만든다.
```
        $ mkdir -p catkin_ws/src
        $ cd catkin_ws
        $ catkin_make
        $ source devel/setup.bash
```
catkin_ws 내부를 보면 세개의 하위 폴더가 생성됨을 볼수 있다.
```    
        /src    --  소스공간
        /build  --  빌드공간
        /devel  --  개발공간
```
소스코드 파일이 포함된 로봇 프로젝트용 패키지를 생서하는 소스공간(/src) 에서 작업한다.
이러한 패키지를 catkin package 라고 한다.
   
catkin package를 만들기 위해서는 터미널에서 다음과같이 입력한다
```
        $ cd ~/catkin_ws/src
        $ catkin_create_pkg  <user_package_name>  std_msgs roscpp rospy 
```
이렇게하면 package.xml, CMakelist.txt 가 포함된 <user_package_name> 폴더가 생성된다.
"std_msgs", "rospy", "roscpp" 는 패키지가 의존하는 종속성 목록이다.
   
catkin_create_pkg를 사용하려면 <package_name>과 선택적으로 해당 패키지가 의존하는 종속성 목록을 제공해야 한다.

형식은 아래와 같다.
```
        $ catkin_create_pkg  <pacakge_name> [depend1] [depend2] [depend3] ...
```

## ROS package build

   

    
    
    
    
    
    
    
    
    
