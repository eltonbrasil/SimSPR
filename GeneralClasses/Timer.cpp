// ***
// Constructor
// ***

Timer::Timer()
{

    startCount.tv_sec = startCount.tv_usec = 0;
    endCount.tv_sec = endCount.tv_usec = 0;

    stopped = 0;
    startTimeInMicroSec = 0;
    endTimeInMicroSec = 0;
}

// ***
// Distructor
// ***

Timer::~Timer()
{
}

// ***
// Start timer. StartCount will be set at this point.
// ***

void Timer::start()
{
    stopped = 0; // reset stop flag

    gettimeofday(&startCount, NULL);

}

// ***
// Stop the timer. EndCount will be set at this point.
// ***

void Timer::stop()
{
    stopped = 1; // set timer stopped flag

    gettimeofday(&endCount, NULL);

}

// ***
// Compute elapsed time in micro-second resolution
// Other getElapsedTime will call this first, then convert to correspond resolution.
// ***

double Timer::getElapsedTimeInMicroSec()
{
    if(!stopped)
        gettimeofday(&endCount, NULL);

    startTimeInMicroSec = (startCount.tv_sec * 1000000.0) + startCount.tv_usec;
    endTimeInMicroSec = (endCount.tv_sec * 1000000.0) + endCount.tv_usec;


    return endTimeInMicroSec - startTimeInMicroSec;
}

// ***
// Divide elapsedTimeInMicroSec by 1000
// ***

double Timer::getElapsedTimeInMilliSec()
{
    return this->getElapsedTimeInMicroSec() * 0.001;
}

// ***
// Divide elapsedTimeInMicroSec by 1000000
// ***

double Timer::getElapsedTimeInSec()
{
    return this->getElapsedTimeInMicroSec() * 0.000001;
}

// ***
// Same as getElapsedTimeInSec()
// ***

double Timer::getElapsedTime()
{
    return this->getElapsedTimeInSec();
}