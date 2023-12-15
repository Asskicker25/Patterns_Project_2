BeginCommandGroup("CarSpawn","Parallel")

    WaitForSeconds(1)
    SpawnCar("PatrolCar1",0)
    BindGameObject("PatrolCar1") 
    MoveWithTime(140, 1, 346,0)
    RotateWithTime(-90,-90,0,0);

EndCommandGroup("CarSpawn")


BeginCommandGroup("PatrolCar1Move","Serial",1)

    WaitForSeconds(3)

     FollowCurveWithTime(6).AddPoint(150,2,346, 0,0,0,  0,0,0)
    .AddPoint(128,2,346, 25,0,0, 0,0,0)
    .AddPoint(102,2,296, 0,0,25, 0,0,0)
    .AddPoint(108,2,255, 0,0,25, 0,0,0)
    .AddPoint(72,2,220,  25,0,0, 0,0,0)
    .LookAtCurve(1).LookAtOffset(-90,180,0)

    WaitForSeconds(1)

    RotateWithTime(90,0,0,3)



EndCommandGroup("PatrolCar1Move")

