**Work in progress!** For use with standard SG90 Servos.

## **Coordinate system reference**

Pedro anthropomorphic arm uses a **right-handed coordinate system** with the following orientation:

  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;•	**Origin**: Located at the base of the robot arm (the center of joint 1)  
    
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;•	**X-axis**: Points forward from the robot base when joint 1 is at 90° (neutral position) 
    
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;•	**Y-axis**: Points to the left from the robot base when joint 1 is at 90° (neutral position)
    
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;•	**Z-axis**: Points upward, perpendicular to the X-Y plane
  
## **Link parameters**

Pedro has the following DH parameters:

  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;•	**D1** = 34.0 mm (Base height along Z-axis)
      
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;•	**A2** = 70.0 mm (Length of link 2)
      
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;•	**A3** = 80.0 mm (Length of link 3)
    
    
    
## **Joint configuration**

The robot has three revolute joints:

  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;•	**Joint 1**: Base rotation (θ1) - rotates around Z-axis (0-180° with standard SG90 servo)
      
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;•	**Joint 2**: Shoulder joint (θ2) - rotates around an axis parallel to Y-axis (0-180° with standard SG90 servo)
      
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;•	**Joint 3**: Elbow joint (θ3) - rotates around an axis parallel to Y-axis (0-180° with standard SG90 servo)
    
    
## **Workspace analysis**

### **Reachable Workspace**

The arm's reachable workspace is defined by:

  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;•	**Minimum reach**: Approximately |A2 - A3| = |70 - 80| = 10 mm 
      
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;o	This occurs when the arm folds back on itself
        
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;•	**Maximum reach**: D1 + A2 + A3 = 184 mm
      
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;o	This occurs when the arm is fully extended
      
      
The workspace is a partial sphere with:

  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;•	**Horizontal sweep**: 0° to 180° (limited by joint 1 servo range)
      
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;•	**Vertical reach**: From nearly the base height (D1) to approximately D1 + A2 + A3 = 184 mm at full extension
    
    
### **Position Limits for Inverse Kinematics**

For a position (x, y, z) to be reachable, the following constraints must be satisfied:

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;1.	**Distance from Z-axis constraint**:

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;o	√(x² + y²) ≤ (A2 + A3) = 150 mm
    
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;o	√(x² + y²) ≥ servo minimum reach for joint 2/3 (determined by joint angle limits)
    
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;2.	**Height constraint**:

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;o	z ≥ D1 - small vertical offset (determined by joint angle limits)
    
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;o	z ≤ D1 + A2 + A3 = 184 mm (maximum at full vertical extension)
    
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;3.	**Total reach constraint**:

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;o	10 mm ≤ √((√(x² + y²))² + (z - D1)²) ≤ 150 mm
    
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;o	The minimum reach may vary based on the physical joint limits of the robot
    
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;4.	**Angular constraints**:

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;o	Joint 1 angle (θ1): 0° to 180°
  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;o	Joint 2 angle (θ2): 0° to 180°
  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;o	Joint 3 angle (θ3): 0° to 180°
  

## **Motion planning considerations**

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;1.	**Singularities** occur when:

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;o	The arm is fully extended
      
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;o	The end effector is touching the base (close to x = 0, y = 0)
      
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;2.	**Joint Limits**: The SG90 servos have a mechanical range of approximately 0° to 180°

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;3.	**Self-collision**: Not implemented in the current version of the library


### **Usage guidelines**

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;1.	Before using the inverse kinematics function, check if the target position is reachable using `isReachable(Position position)`
       
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;2.	If a position is unreachable, the arm will not move
       
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;3.	For smoother motion, use `moveSmooth()` instead of direct `move()`

### **Error handling**

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The inverse kinematics solver returns:

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;•	*true* if a valid solution was found
  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;•	*false* if the position is unreachable or joint limits would be violated

  
### **Initialization**
  
The robot initializes in the neutral position (90°, 90°, 90°) which positions the arm:
  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;•	Pointing forward (along the X-axis)
  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;•	At a height of D1 + A2sin(90°) + A3sin(90°) = 34 + 70 + 80 = 184 mm
