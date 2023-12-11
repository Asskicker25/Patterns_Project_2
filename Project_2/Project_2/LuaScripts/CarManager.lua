BeginCommandGroup("CarSpawn","Parallel")

    WaitForSeconds(1)
    SpawnCar("PatrolCar1",0)
    BindGameObject("PatrolCar1") 
    MoveWithTime(140, 1, 346,0)
    RotateWithTime(-90,-90,0,0);

    WaitForSeconds(3)


    FollowCurveWithTime(6).AddPoint(139,2,346, 110,2,360)
    .AddPoint(105,2,304,  85,2,320)
    .AddPoint(105,2,280,  105,2,281)
    .AddPoint(105,2,253,  135,2,223)
    .AddPoint(105,2,221,  105,2,195)
    .AddPoint(70,2,221,   70,2,219)
    .LookAtCurve(1).LookAtOffset(-90,180,0)

    WaitForSeconds(7)

    FollowCurveWithTime(8).AddPoint(70,2,221,   70,2,219)
    .AddPoint(-110,2,221,   -110,2,219)
    
    .LookAtCurve(1).LookAtOffset(-90,180,0)


EndCommandGroup("CarSpawn")