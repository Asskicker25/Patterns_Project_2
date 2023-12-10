BeginCommandGroup("CarSpawn","Parallel")

    WaitForSeconds(1)
    SpawnCar("PatrolCar1",0)
    BindGameObject("PatrolCar1") 
    MoveWithTime(140, 1, 346,0)
    RotateWithTime(-90,-90,0,0);

    FollowCurveWithTime(30).AddPoint(139,2,346, 100,2,370)
    .AddPoint(105,2,304,  70,2,320).LookAtTangent(1).LookAtOffset(-90,-90,0)

EndCommandGroup("CarSpawn")