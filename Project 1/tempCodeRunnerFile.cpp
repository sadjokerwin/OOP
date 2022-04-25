nt main()
{
    Time t1(13, 25, 0);
    Time t2(12, 0, 0);
    Time t3;
    t3 = t1 - t2;
    cout << t3.getHours() << ":" << t3.getMins() << ":" << t3.getSeconds();
    return 0;
}