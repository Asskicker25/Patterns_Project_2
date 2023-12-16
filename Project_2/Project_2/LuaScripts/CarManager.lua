BeginCommandGroup("CarSpawn","Parallel")

    SpawnCar("PatrolCar1",0)
    BindGameObject("PatrolCar1") 
    MoveWithTime(140, 1, 346,0)
    RotateWithTime(-90,-90,0,0);

    SpawnTriggerZone("SpawnTruck", 30,30,30)
    BindGameObject("SpawnTruck")
    MoveWithTime(0,2,346, 0)

EndCommandGroup("CarSpawn")

BindGameObject("PatrolCar1") 
BeginCommandGroup("PatrolCar1Move","Serial",1)

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

    RotateWithTime(270,90,0,1)

    MoveWithTime(150,2,346, 5)
    RotateWithTime(270,270,0,1)

EndCommandGroup("PatrolCar1Move")

