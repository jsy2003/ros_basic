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

## ROS Topic
Topic은 노드가 메세지를 교환하는 명명된 버스이다. 이것은 ROS 에서 노드에 대해 가장 일반적으로 사용되는 통신모드이다.
이 모드에서 노드는  topic 이름이 있는 메세지를 브로드캐스팅 한다. 이 브로드캐스트 노드를 publisher 노드라고 한다.

메세지를 수신하려는 노드를 subscriber 노드라고 한다.

이 통신 모드는 단방향이다. 이 노드는 자신이 누구와 통신하고 있는 알지 못한다. 즉, publisher 는 subscriber 가 없거나 여러명 있어서 계속 publish 한다. 마찬가지로 subscriber 는 publisher 가 없거나 여러개인 경우 topic 을 계속 subscribe 한다.publisher 와 subscriber 가 동일한 topic에 대해 연결을 설정하는 것은 ROS 마스터이다.

Topic은 주로 센서데이타, 로봇관정상태 등과 같은 연속적인 데이타 스트림에 가방 적합하다.

## Publisher/ Subscriber node coding
### python 코드:
scripts 폴더로 이동하여 py_publisher.py 와 py_subscriber.py 파일을 작성한다음 실행 파일로 만들고 실행시킨다.
실행하기전에 roscore을 먼저실행한다.

 #### [py_publisher.py]
```     
      
        #!/usr/bin/env python
        
        from std_msgs.msg import Int32
        rospy.init_node("publisger_py")
        pub = rospy.Publisher("topic_py", Int32, queue_size=10)
        rospy.loginfo("publisher_py node started and publishing data on topic_py")
        rate = rospy.Rate(10)
        count=Int32()
        count.data = 0
        while not rospy.is_shutdown():
                pub.publish(count)
                count.data += 1
                rate.sleep()
```

#### [py_subscriber.py]

```     
        #!/usr/bin/env python
        
        import rospy
        from std_msgs.msg import Int32
        
        def my_callback(msg):
                rospy.loginfo("received data from topic_py: %d", msg.data)
        
        rospy.init_node("subscriber_py")
        rospy.Subscriber("topic_py", Int32, my_callback, queue_size=10)
        rospy.loginfo("subscriber_py node started and subscribed to topic_py") #debug statement
        rospy.spin()
```

### C++ 코드
src 폴더로 이동하여 cpp_publisher.cpp 와 cpp_subscriber.cpp 파일을 작성한다.
그런다음 CMakelist.txt 파일을 수정한다음 빌드하고 실행한다

#### [cpp_publisher.cpp]
```
        #include <ros/ros.h>
        #include <std_msgs/Int32.h>
        
        int main(int argc, char **argv)
        {
                ros::init(argc, argv, "publisher_cpp");
                ros::NodeHandle nh;
                
                ros::Publisher pub = nh.advertise<std_msgs::Int32>("topic_cpp", 10);
                ROS_INFO("publisher_cpp node started and publishing data on topic_cpp");
                ros::Rate loop_rate(10);
                std_msgs::Int32 count;
                count.data = 0;
                whule(ros::ok())
                {
                        pub.publish(count);
                        count.data++;
                        loop_rate.sleep();
                 }
                 return 0;
         }
```

#### [cpp_subscriber.cpp]
```
        #include <ros/ros.h>
        #include <std_msgs/Int32.h>
        
        void my_callback(const std_msgs::Int32::ConstPtr &msg)
        {
                ROS_INFO("received data from topic_cpp: [%ld]", (long int)msg->data);
        }
        
        int main(int argc, char **argv)
        {
                ros::init(argc, argv, "subscriber_cpp");
                ros::NodeHandle nh;
                ros::Subscriber sub = nh.subscribe("topic_cpp", 10, my_callback)
                ROS_INFO("subscriber_cpp node started and subscribed to topic_cpp");
                ros::spin();
                return 0;
        }
```

#### [CMakeList.txt]
```
        add_executable(pubslisher_cpp src/cpp_publisher.cpp)
        target_link_libraries(publisher_cpp ${catkin_LIBRARIES})
        
        add_executable(subscriber_cpp src/cpp_subscriber.cpp)
        target_link_libraries(scriber_cpp ${catkin_LIBRARIES})
```

### topic  명령
```
        $rostpic list                   --> 노드별로 pubslisher/subscriber topic 나열
        $rostopic info /topic_name      --> 특정 topic 정보
        $rostipic type /topic_name      --> topic 메세지 유형
        $rostopic echo /topic_name      --> 터미널에 topic 데이타 출력
        $rostopic pub /topic_name [messagetype] "data:value"
            --> $rostopic pub /topic_name std_msgs/Int32 "data:10"
```

## ROS Service
ROS 서비스는 양방향 통신을 한다. 서비스를 제공하는 노드를 서비스 server node, 서비스를 요청하는 노드를 서비스 client node라한다.
ROS 노드는 문자열 이름으로 서비스를 제공하고 클라이언트는 요청 메세지를 모내고 응답을 기다리면서 서비스를 호출한다.

서비스는 노드 상태를 쿼리 하거나 IK 와 같은 빠른 계산을 수행하는 것과 같이 빠르게 종료되는 작업에 사용한다.
특정 데이타를 요청하는 것과 같이 비교적 빠른 작업에 주로 사용된다.

데이타를 setup 하거나 설정된 데이타를 읽거나 등등...

### 파이썬 코드
스크립터 폴더로 이동하여 py_service_server.py, py_service_client.py 파일을 작성한다.

####[py_service_server.py]
```
        #!/usr/bin/env python
        
        import rospy
        from rospy_tutorial.srv import AddTwoInts, AddTwoIntsResponse, AddTwoIntRequest
        
        def my_server(req):
                res = AddTwoIntsResponse()
                rospy.loginfo("Request received to add: %d & %d", req.a, req.b)
                res.sum = req.a + req.b
                return res
        
        rospy.init_node('service_server_node_py') 
        rospy.Service('add_py", AddTwoInts, my_server)
        rospy.loginfo("Python Service server ready to add two numbers")
        rospy.spin()
```

####[py_service_client.py]
```
        #!/usr/bin/env python
        
        import rospy
        from rospy_tutorial.srv import AddTwoInts, AddTwoIntsResponse, AddTwoIntRequest
        
        rospy.init_node("service_client_node_py",anonymous=True) 
        rate = rospy.Rate(1)
        
        x = 0
        y = 1
        element = 1
        rospy.wait_for_service("add_py")
        
        add = rospy.ServiceProxy("add_py", AddTwoInts)
        
        rospy.loginfo("Fibanocci series element 0: 0")
        while not rospy.is_shutdown() and element < 81:
                resp = add(x,y)
                rospy.loginfo("Fibanocci series element %d: %d", element, resp.sum)
                x=y
	        y=resp.sum
	        element+=1
	        rate.sleep()
```

### C++ 코드
스크립터 폴더로 이동하여 cpp_service_server.cpp, cpp_service_client.cpp 파일을 작성한다.
CMakeList.txt 수정하고 빌드한다.

#### [cpp_service_server.cpp]
```
        #include "ros/ros.h"
        #include "rospy_tutorials/AddTwoInts.h" 

        bool my_server(rospy_tutorials::AddTwoInts::Request &req, rospy_tutorials::AddTwoInts::Response &res)
        {
	        ROS_INFO("Request receiced to add: x=%ld and y=%ld ", (long int)req.a, (long int)req.b);
	        res.sum = req.a + req.b;
	        return true;
        }

        int main(int argc, char **argv)
        {
	        ros::init(argc, argv, "service_server_node_cpp"); 
	        ros::NodeHandle nh; 

	        ros::ServiceServer service = nh.advertiseService("add_cpp", my_server);
	        ROS_INFO("Cpp Service server ready to add two numbers");
	
	        ros::spin();

	        return 0;
        }
```

#### [cpp_service_client.cpp]
```
        #include "ros/ros.h"
        #include "rospy_tutorials/AddTwoInts.h" 
        int main(int argc, char **argv)
        {
	        ros::init(argc, argv, "service_client_node_cpp"); 
	        ros::NodeHandle nh;

	        ros::ServiceClient client = nh.serviceClient<rospy_tutorials::AddTwoInts>("add_cpp");
	
	        rospy_tutorials::AddTwoInts var; 
	
	        ros::Rate loop_rate(1); // 1 hz
	
	        var.request.a = 0;
	        var.request.b = 1;
	        int element =1;
	
	        ROS_INFO("Fibanocci series element %d = %d", element, var.response.sum);
	        while (ros::ok() && element < 81)
                {
		        client.call(var);
		
		        ROS_INFO("Fibanocci series element %d = %d", element, var.response.sum);
		
		        var.request.a = var.request.b;
		        var.request.b = var.response.sum;
		        element++;
		
		        loop_rate.sleep(); // This makes the loop to iterate at 1 Hz i.e., once in 1 sec.	
	        }
	        return 0;
        }
```

#### [CMakeList.txt]
```
        add_executable(service_server_cpp src/cpp_service_server.cpp)
        target_link_libraries(service_server_cpp ${catkin_LIBRARIES})
        
        add_executable(service_client_cpp src/cpp_service_client.cpp)
        target_link_libraries(service_client_cpp ${catkin_LIBRARIES})
```


### service 명령
```
        $rosservice list
        $rosservice info /service_name
        $rosservice node /service_name
        $rosservice type /serevide_name
        $rosservice call /service_name service-args
           --> $rosservice call /add_py "a:10"
```

## ROS Action
요청된 클라이언트에 대한 작업을 실행하는 서비스를 보았습니다. 그러나 서비스에는 단점이 있습니다. 
클라이언트에서 서비스를 요청하면 요청이 전역 콜백 대기열에 할당됩니다. 
어떤 이유로든 이 서비스가 작업을 완료하는 데 오랜 시간이 걸리면 다른 노드에 부작용이 있을 수 있습니다. 

따라서 서비스는 더 오래 실행되는 프로세스, 특히 예외적인 상황이 발생하는 경우 선점해야 할 수 있는 프로세스에 사용되어서는 안 됩니다. 
그러나 경우에 따라 서비스를 실행하는 데 시간이 오래 걸리는 경우 사용자는 실행 중에 요청을 취소하거나 요청이 어떻게 진행되고 있는지에 대한 정기적인 피드백을 받는 기능을 원할 수 있습니다. 

actionlib의 패키지를 만들 수있는 도구를 제공 서버 의 목표를 장기 실행 실행하고 필요한 경우 그 선점 할 수있다. 
또한 서버에 요청을 보내기 위해 클라이언트 인터페이스를 제공 합니다.

간단하게 하기 위해 이번에는 추적 기능이 있는 음식 배달 모바일 앱의 비유를 사용하겠습니다.

배달원의 현재 위치와 주문 취소 옵션을 제공하는 모바일 앱을 통해 식당에서 온라인으로 음식을 주문했다고 가정해 보겠습니다. 
이제 배달원의 위치를 추적하고 집에 도착하는 시간을 예상할 수 있습니다. 
어째서인지 교통체증, 배달원은 한 곳에서 오랫동안 치입니다. 그러면 이미 오래 기다리다 먹는 것에 흥미를 잃었기 때문에 주문을 취소할 수 있습니다.

여기에서 모바일 앱은 액션 서버 이고, 당신은 액션 클라이언트 이며, 문 앞에 있는 배달 소년은 목표 이며 배달 소년의 현재 위치는 피드백 입니다. 
그리고 주문 취소 옵션 은 목표 선점 입니다.


사용법: 액션은 로봇 동작 또는 인식 실행과 같은 더 긴 작업에 사용됩니다








