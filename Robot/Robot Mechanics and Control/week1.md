#![](http://i.imgur.com/S7xBFja.png)Sundy
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
