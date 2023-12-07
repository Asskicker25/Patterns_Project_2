BeginCommandGroup("Init","Serial",3);


    --MoveWithTime(-6,9,30,0)
    --RotateWithTime(0,90,0,0);
    
   -- WaitForSeconds(2.5);

    --MoveWithSpeed(10,9,30,1);
    --MoveWithTime(10,9,30,2.5)
    --WaitForSeconds(2.5);
    --MoveWithTime(0,0,0,1)

EndCommandGroup()

BeginCommandGroup("Move","Parallel",3);

    --WaitForSeconds(5);
    --MoveWithTime(-6,9,30,2.5)

    --MoveWithSpeed(0,9,30,1);
    --RotateWithTime(0,-90,0,0.5);

    --MoveWithTime(-10,9,30,5)
    --RotateWithTime(0,90,0,5);
    --WaitForSeconds(2.5);
    --MoveWithTime(0,0,0,1)

EndCommandGroup()



