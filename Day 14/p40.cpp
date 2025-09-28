//attending-workshops

#include<bits/stdc++.h>

using namespace std;

//Define the structs Workshops and Available_Workshops.
struct Workshop {
    int start_time;
    int duration;
    int end_time;
};
struct Available_Workshops {
    int n;
    Workshop* workshops;
};
//Implement the functions initialize and CalculateMaxWorkshops
Available_Workshops* initialize(int start_time[], int duration[], int n) {
    Available_Workshops* aw = new Available_Workshops;
    aw->n = n;
    aw->workshops = new Workshop[n];
    for (int i = 0; i < n; i++) {
        aw->workshops[i].start_time = start_time[i];
        aw->workshops[i].duration = duration[i];
        aw->workshops[i].end_time = start_time[i] + duration[i];
    }
    return aw;
}

int CalculateMaxWorkshops(Available_Workshops* aw) {
    // Sort workshops by their end time
    sort(aw->workshops, aw->workshops + aw->n, [](const Workshop& a, const Workshop& b) {
        return a.end_time < b.end_time;
    });

    int count = 0;
    int last_end_time = 0;

    for (int i = 0; i < aw->n; i++) {
        if (aw->workshops[i].start_time >= last_end_time) {
            count++;
            last_end_time = aw->workshops[i].end_time;
        }
    }

    return count;
}

int main() {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
