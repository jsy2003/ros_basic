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
패키지를 빌드하려면 아래명열을 입력하고, ROS 환경를 업데이트 해야한다.
```
        $ cd ~/catkin_ws
        $ catkin_make
        $ source /devel/setup.bash
```
선택한 패키지만 빌드할경우 아래 명령을 사용한다.
```
        $ cd ~/catkin_ws
        $ catkin_make --pkg <package1> <package2>...
        $ source devel/setup.bash
```

## ROS node
ROS node 는 로봇을 실행하기 위한 코드 조각(실행파일)이다. 로봇 어플리케이션은 하나이 상의 노드를 가질수 있다.
예를들어 역기구학을 계산하는 노드, 액추에이터에 명령을 보내는 노드, 센서등에서 관절값을 가져오는 노드 등등...
이 모든 노드는 메세지를 통해 서로 통신한다. 이 모든 노드를 관장하기 위해 하나의 마스터 노드가 있다.

이 마스터노드를 roscore 라고하고 노드를 실행하기전에 제일먼저 실행되어야 한다.

노드가 통신할수 있는 세가지 모드가 있다. topic, service, action 

## ROS node coding
노드는 c++, 파이썬 으로 코딩할수 있다.

### 파이썬 노드 코딩

catkin_ws/src 에 패키지를 생서한다음 그 안에 scripts 라는 폴더를 만들다.
```
        $ cd ~/catkin_ws/src/tutorials
        $ mkdir scripts
```
scripts 폴더안에 simple_node.py 파일을 만든다. 이 파일에서 "simple_node_py" 라는 이름으로 노드를 초기화하고
노드가 종료될때까지 루프를 실행한다.
```
        #!/usr/bin/env python or python3
        import rospy
        count =0
        rospy.init_node("simple_node_py")
        rate= rospy.Rate(10)            # 10hz
        while not rospy.is_shutdown():
                rospy.loginfo("simple_node in python is running. count= %d",count) #debug statement
                count +=1
                rate.sleep()
```
파이썬으로 만든 노드를 실행 가능하게 하기 위해서는 아래명령을 한번 실행해야 한다
```
        $ cd ~/catkin_ws/src/toturials/scripts
        $ chmod +x simple_node.py
```
파일을 실행가능하게 만든후 ROS 환경에서 파일을 업데이트 해야 한다.
```
        $ cd ~/catkin_ws
        $ source devel/setup.bash
```
ROS 노드를 실행하기전에 ROS 마스터 노드를 실행해야 한다. ROS 마스터 노드가 없으면 노드를 실행할수 없다.
따라서 노드를 실행하디 전에 별도의 터미널에서 마스트 노드를 실행해야 한다.
```
        $ roscore
```
만들어진 노들 실행하기 위해서는 아래의 명령을 별도의 터미널에서 아래의 명령을 입력한다.
```
        $ rosrun tutorials simple_node.py
```
### /roscore 터미널
![image](https://user-images.githubusercontent.com/93853610/144700369-719af70e-5726-426b-b92b-2f2a1dbaf822.png)

### /simple_node_py 터미널
![image](https://user-images.githubusercontent.com/93853610/144700407-c0138029-c566-4b35-b889-81290aba5bd7.png)

노드를 중지할때는 Ctrl+C 를 사용한다.

Python 노드를 실행하는 형식은 아래와 같고, 파이썬으로 노드를 만들때는 패키지를 빌드할필요가 없다.
```
        $ rosrun <패키지 이름> <파이썬 노드 이름>
```

### c++ 노드 코딩
패키지의 /src 폴더로 이동한다음 simple_node.cpp 파일을 만든다. 이파일에서도 "simple_node_cpp" 라는 이름의 노드를 
초기화 하고 Ctrl+c 를 눌러 종료될때까지 루프를 실행한다.
```
        #include <ros/ros.h>
        int main(int argc, char **argv)
        {
                int count=0;
                ros::init(argc, argv, "simple_node_cpp");
                ros::NodeHandle nh;
                ros::Rate loop_rate(10);
                while(ros::ok())
                {
                        ROS_INFO("simple_node in cpp is running. count= %d",count);// Debug statement
                        ros::spinOnce();
                        count++;
                        loop_rate.sleep();
                 }
          }
```
CPP 로 작성된 노드를 실행가능하게 하여면 CmakeList.txt 에 아래의 내용을 추가해야 한다음
패키지를 빌드한다.
```
        add_executable(simple_node_cpp src/simple_node.cpp)
        target_link_libraries(simple_node_cpp ${catkin_LIBRARIES})
```
```
        $ cd ~/catkin_ws
        $ catkin_make
        $ source devel/setup.bash
```
마찬가지로 roscore 를 실행하고 아래 명령으로 노드를 실행한다.
```
        $ rosrun tutorials simple_node_cpp
```

### 노드와 관련된 명령 일부
```
        $ rosnode list                  --> 활성노드들을 나열한다
        $ rosnode info /node_name       --> 특정노드의 정보를 얻는다
        $ rosnode kill /node_name       --> 실행중인 노드 종료
```

## ROS message
ROS 메세지는 노드간 정보를 전소하기 위해 Topics, Service 및 Actions 에 대한 데이타 구조이다.
- Topic
Topic 메세지는 .msg 파일에 있다. Topic 메세지 형식은 아래와 같다.
```
        filetype1 filename1     --> Int32    a
        filetype2 filename2     --> Float64  b
        filetype3 filename3     --> Bool     c
        ...
```
- Service
Service 메세지는 .srv 파일에 있다. 이 메세지는 두 부분으로 구성된다. Request 와 Response 이다.
요구와 응답은 '---' 구분한다. 형식은 아래와 같다
```
        #Request
        fieldType1      fieldname1
        ..
        ---
        #Response
        fieldType2      fieldName2
        ...
```
- Action
Action은 .action 파일에 있다. 이 메세지는 세부분으로 구성된다. 목표, 결과, 피드백 부분으로 구성된다.
구분을 '---' 구분한다. 형식은 아래와 같다.
```
        #goal
        fieldType1   fieldName1
        ...
        ---
        #result
        filedType2   filedName2
        ...
        ---
        #feedback
        filedType3   filedName3
        ...
```
ROS 에는 미리정의된 많은 메세지가 있다(ROS 위키 메세지 참조)
또한 사용자 정의 메세지를 만드들어 사용할수 있다(CMakeList.txt 참조)

### 메세지 관련 명령 일부
```
        $rosmsg list            --> topic, action  메세지를 보여줌
        $rossrv list            --> service 메세지를 보여줌
        
        $rosmsg <package_name>  --> 메세지파일을 포함하는 패키지 목록 
        $rossrv <package_name>
        
        $rosmsg show package_name/message_name  --> 메세지 형식을 나열
        $rossrv show package_name/message_name
        
        <예>
        $rosmsg show std_msgs/Int32
        $rossrv show tutorials/AddTwoInts
        
```














