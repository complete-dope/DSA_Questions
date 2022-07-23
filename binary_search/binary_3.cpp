// their are only 2 types of dp

/*

//TYPE-1
--> Most of the questions this will work 
int start = 0;
int end = n-1;
while(start <= end)
{

    start = mid+1;
    end = mid-1;
}

// TYPE-2
--> when the mid can also be the ans (depends on question)
int start= 0;
int end = n; // not n-1;

while(start < end)
{
    strt = mid+1;
    end = mid;
}


*/