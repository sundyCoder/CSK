#![](http://i.imgur.com/AsHqrkf.png)
##![](http://i.imgur.com/S7xBFja.png)Robot Mechanics and Control, Part 1
##![](http://i.imgur.com/S7xBFja.png)Week 1
###Course Introduction
###1.1 Degrees of freedom, grasp statics, forward and inverse kinematics
Basic concepts: links, joint, open chain, closed chain,rigid body,end-effector, orientations, rigid-body motions. nonredundant robots, redundant robots.

**A typical robot consists of joints, links, and an end-effector**

- **DOF**: Degree Of freedom(how many motors/joints do we need?),count the number of links, count the number of joints, and come up with the degrees of freedom, or the number of joints that can be independently actuated.
- **Grasping**: how many fingers should I use, where should I place the fingers?" Is it better to use three fingers, or four fingers? If I use thee fingers, is it better to grasp it this way, or to grasp it another way?
- **Forward kinematics**:If you give me the joint values, theta1 and theta2, then I can tell you exactly where the hand is using this equation. This is called the forward kinematics.
![](http://i.imgur.com/ej0LXf9.jpg)
- **Inverse Kinematics(opposite of the forward kinematics)**:In this case what we are doing is, we are given Px, Py, the desired location of the hand, and we want to find the joint values theta1, theta2 that will move the robot to the desired hand location.

###1.2. Velocity analysis, planning, and control
- **Jacobian matrix**: Suppose the inputs to tue robots are velocities.I use the Jacobian to determine the necessary velocities.
- **Planning**: This is the actual path and this white path was my desired path. So what happened? Why is it doing this? Why is it not behaving the way I want it to?  
	ERRORS: 
	- noise
	- disturbances
	- kinematics
	- parameter errors
	- friction(摩擦)
	- elasticity(弹性)
	- backlash
	- other unmodeled errors.
- **Feedback control**: The idea is to use measurements of the current state to compensate for the control so as to correct for errors.

###Robot Configuration Space
###1.1.Joints, links, mechanisms, configuration space, degrees of freedom
1. where is the robot?
	1. pick a reference frame: Reference frame:参考坐标，坐标系统
	2. pick 3 points{A,B,C} on coin.
		1. what's the contraints are?   d(A,B),d(B,C),d(A,C), 3 equations , 6 unknow parameters.
	3. A better way to describe the location of a robot (x,y,theta)
	
Now, consider a rigid body in a 3-D space.(x,y,z)

d(A,B) = L1(fixed), d(A,C) = L2(fixed),d(B,C) = L3(fixed).
3 equations, 9 unknows --> 9-3 = 6 independant parameters.
![](http://i.imgur.com/bH8xXS1.png)

Mobility of robot Mechanisms:

- some common joints:
	1. 	Revolute(R) joint
	1. 	Prismatic(P) joint(linear joint)
	1. 	cylindrical(C) joint
![](http://i.imgur.com/2MfcJAs.png)
	1. Universal joint(U)
	![](http://i.imgur.com/DMkMH2B.png)
	1. Spherical Joint（S)
	
	![](http://i.imgur.com/p4EcpaO.png)

The R joint has one degree of freedom.
C and U joints have 2 dof
the S joint has 3 dof.

![](http://i.imgur.com/38taZt9.png)
![](http://i.imgur.com/KAgSSB8.png)

every time you see a joint connecting two bodies, that eliminates two coordinates.

![](http://i.imgur.com/ne9syfN.png)
