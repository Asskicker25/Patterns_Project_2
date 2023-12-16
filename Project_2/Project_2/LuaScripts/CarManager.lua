BeginCommandGroup("CarSpawn","Parallel")

    SpawnCar("PatrolCar1",0)
    BindGameObject("PatrolCar1") 
    MoveWithTime(140, 1, 346,0)
    RotateWithTime(-90,-90,0,0);

    SpawnTriggerZone("SpawnTruck",0,2,346, 30,30,30)

EndCommandGroup("CarSpawn")

BindGameObject("PatrolCar1") 
BeginCommandGroup("PatrolCar1Move","Serial", -1)

    WaitForSeconds(3)

    FollowCurveWithTime(6)
    .AddPoint(150,2,346, 0,0,0,  0,0,0)
    .AddPoint(128,2,346, 25,0,0, 0,0,0)
    .AddPoint(102,2,296, 0,0,25, 0,0,0)
    .AddPoint(108,2,255, 0,0,25, 0,0,0)
    .AddPoint(72,2,220,  25,0,0, 0,0,0)
    .LookAtCurve(1).LookAtOffset(-90,180,0)

    MoveWithTime(-110,2,220, 6).EaseIn("Quart",2).EaseOut("Bounce",0.5)

    WaitForSeconds(1)

    FollowCurveWithTime(4)
    .AddPoint(-110,2,220, -25,0,0)
    .AddPoint(-145,2,260, 0,0,-25)
    .AddPoint(-145,2,310, 0,0,-25)
    .AddPoint(-75,2,350,  5,0,0)
    .LookAtCurve(1).LookAtOffset(-90,180,0)

    SetCollisionState(1)

    RotateWithTime(270,90,0,1)

    MoveWithTime(150,2,346, 5)
    RotateWithTime(270,270,0,1)

EndCommandGroup("PatrolCar1Move")


BindGameObject("PatrolCar1")
BeginCommandGroup("SpawningTruck", "Parallel").SetCollisionCondition("SpawnTruck")

    SpawnCar("PatrolCar2",1)
    BindGameObject("PatrolCar2") 
    MoveWithTime(0,2,346,0)
    RotateWithTime(-90,90,0,0);

EndCommandGroup("SpawningTruck")


BindGameObject("PatrolCar1")
BeginCommandGroup("MovingTruck","Serial").SetCollisionCondition("SpawnTruck")

    BindGameObject("PatrolCar2") 

    MoveWithTime(0,2,346, 0)
    
    WaitForSeconds(2)
    RotateWithTime(-90,-90,0, 2).EaseIn("Sine",0.5).EaseOut("Sine",0.5)
    RotateWithTime(-90,-270,0, 2).EaseIn("Sine",0.5).EaseOut("Sine",0.5)
    WaitForSeconds(3)

    FollowCurveWithTime(7)
    .AddPoint(0,2,346, 0,0,0)
    .AddPoint(70,2,346, -25,0,0)
    .AddPoint(102,2,296, 0,0,25)
    .AddPoint(108,2,255, 0,0,25)
    .AddPoint(72,2,220,  25,0,0)
    .LookAtCurve(1).LookAtOffset(-90,180,0)

    FollowObject("PatrolCar1",4).SetFollowDistance(10).SetFollowOffset(0,0,0).SetMaxSpeed(0.01).SetAccelerationRange(30).SetAccelerationRange(60)

EndCommandGroup("MovingTruck")


