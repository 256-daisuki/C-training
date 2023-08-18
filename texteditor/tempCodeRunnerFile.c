  printf("\e[2J\e[1;1H");//clear
    if(argc != 2) {
        printf("[error]illegal args\n");
    } else {
        file_print(argv[1]);
    }