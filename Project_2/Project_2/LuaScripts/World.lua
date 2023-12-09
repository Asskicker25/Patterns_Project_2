
BindGameObject("Player") 
BeginCommandGroup("Player","Serial")
    MoveWithTime(-6,9,30,0)
    RotateWithTime(0,90,0,0);

    WaitForSeconds(2.5)
    
    FollowCurveWithTime(5).AddPoint(-5,9,30,  10,9,0).AddPoint(40,9,30,  30,9,60).EaseIn("Sine",2).EaseOut("Sine",2)
    
EndCommandGroup("Player")

BindGameObject("Player") 
BeginCommandGroup("PlayerOnCollision","Serial").SetCollisionCondition("Zone1")

    WaitForSeconds(2);
    MoveWithTime(-6,9,30,5);

EndCommandGroup("PlayerOnCollision")

BeginCommandGroup("TriggerZone","Parallel")

    SpawnTriggerZone("Zone1", 10, 10,10)
    BindGameObject("Zone1") 
    MoveWithTime(50, 9, 30,0)

EndCommandGroup("TriggerZone")

BeginCommandGroup("CarSpawn","Parallel")
    SpawnCar("Car1",0)
    BindGameObject("Car1") 
    MoveWithTime(30, 9, 30,0)
    RotateWithTime(-90,90,0,0);

    SpawnCar("Car2",0)
    BindGameObject("Car2") 
    MoveWithTime(-10, 9, 30,0)
    
    WaitForSeconds(0.01);

    BindGameObject("Car1") 
    MoveWithTime(80, 9, 30,5)
   
    WaitForSeconds(2);

    BindGameObject("Car2") 
    FollowObject("Car1").SetFollowDistance(20).SetFollowOffset(0,0,0).SetMaxSpeed(0.01).SetDeaccelerationRange(30).SetAccelerationRange(60)

EndCommandGroup("CarSpawn")
