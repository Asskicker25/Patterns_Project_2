BeginCommandGroup("CarSpawn","Parallel")

    WaitForSeconds(1)
    SpawnCar("PatrolCar1",0)
    BindGameObject("PatrolCar1") 
    MoveWithTime(140, 1, 346,0)
    RotateWithTime(-90,-90,0,0);

    WaitForSeconds(3)


    FollowCurveWithTime(6).AddPoint(139,2,346, 0,0,-20,  90,0,0)
    .AddPoint(80,2,346, 0,0,-20 ,-90,0,0)
    .AddPoint(10,2,346, 0,0,20 ,0,0,0)
    --.AddPoint(105,2,253,  135,2,223)
    --.AddPoint(105,2,221,  105,2,195)
    --.AddPoint(70,2,221,   70,2,219)
    .LookAtCurve(1).LookAtOffset(-90,180,0)

    WaitForSeconds(7)

    --FollowCurveWithTime(8).AddPoint(70,2,221,   70,2,219)
    --.AddPoint(-110,2,221,   -110,2,219)
    
    --.LookAtCurve(1).LookAtOffset(-90,180,0)


EndCommandGroup("CarSpawn")