#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#define MAX_SIZE 50

#define CYAN    11
#define GREEN   10
#define YELLOW  14
#define RED     12
#define WHITE   15
#define BLUE    9
#define MAGENTA 13

/* ============================================================
   UTILITY FUNCTIONS
   ============================================================ */

void setColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void clearScreen()
{
    system("cls");
}

void pressEnter()
{
    setColor(YELLOW);
    printf("\nPress Enter to continue...");
    getchar();
    getchar();
}

void printArray(int arr[], int n)
{
    printf("[ ");

    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);

        if (i < n - 1)
            printf("  ");
    }

    printf(" ]\n");
}

void printSeparator()
{
    setColor(CYAN);
    printf("\n------------------------------------------------------------\n");
    setColor(WHITE);
}

void showHeader()
{
    setColor(CYAN);

    printf("\n");
    printf("============================================================\n");
    printf("                         SORTLAB                            \n");
    printf("============================================================\n");

    setColor(WHITE);

    printf("          INSERTION SORT  &  SHELL SORT\n");
    printf("             Interactive DSA Learning Tool\n");

    setColor(CYAN);
    printf("============================================================\n");

    setColor(WHITE);
}

/* ============================================================
   LEARN INSERTION SORT
   ============================================================ */

void learnInsertionSort()
{
    clearScreen();
    showHeader();

    setColor(GREEN);
    printf("\n                 INSERTION SORT\n\n");

    setColor(WHITE);

    printf("WHAT IS INSERTION SORT?\n\n");
    printf("Insertion Sort builds the sorted array one element\n");
    printf("at a time, similar to arranging playing cards.\n\n");

    printf("BASIC IDEA\n\n");
    printf("1. Start from the second element.\n");
    printf("2. Select it as the KEY.\n");
    printf("3. Compare KEY with elements on its left.\n");
    printf("4. Shift larger elements to the right.\n");
    printf("5. Insert KEY into its correct position.\n");
    printf("6. Repeat until the array is sorted.\n");

    printSeparator();

    setColor(YELLOW);
    printf("EXAMPLE\n\n");

    setColor(WHITE);

    printf("Original : [ 5  3  8  4  2 ]\n");
    printf("Pass 1   : [ 3  5  8  4  2 ]\n");
    printf("Pass 2   : [ 3  5  8  4  2 ]\n");
    printf("Pass 3   : [ 3  4  5  8  2 ]\n");
    printf("Pass 4   : [ 2  3  4  5  8 ]\n");

    setColor(GREEN);
    printf("\nResult: Sorted in ascending order.\n");

    pressEnter();
}

/* ============================================================
   LEARN SHELL SORT
   ============================================================ */

void learnShellSort()
{
    clearScreen();
    showHeader();

    setColor(GREEN);
    printf("\n                    SHELL SORT\n\n");

    setColor(WHITE);

    printf("WHAT IS SHELL SORT?\n\n");
    printf("Shell Sort is an improvement over Insertion Sort.\n");
    printf("Instead of comparing only nearby elements, it uses\n");
    printf("a GAP to compare elements farther apart.\n\n");

    printf("BASIC IDEA\n\n");
    printf("1. Choose an initial GAP.\n");
    printf("2. Compare elements separated by the GAP.\n");
    printf("3. Shift larger elements when required.\n");
    printf("4. Reduce the GAP.\n");
    printf("5. Repeat the process.\n");
    printf("6. Finish when GAP becomes 1.\n");

    printSeparator();

    setColor(YELLOW);
    printf("EXAMPLE\n\n");

    setColor(WHITE);

    printf("Original : [ 8  5  3  7  6  2  4  1 ]\n\n");
    printf("GAP = 4  -> Compare distant elements\n");
    printf("GAP = 2  -> Reduce the distance\n");
    printf("GAP = 1  -> Final insertion-sort phase\n");

    setColor(GREEN);
    printf("\nResult: Array becomes sorted.\n");

    pressEnter();
}

/* ============================================================
   CONCEPT COMPARISON
   ============================================================ */

void compareConcepts()
{
    clearScreen();
    showHeader();

    setColor(GREEN);
    printf("\n                COMPARE THE CONCEPTS\n\n");

    setColor(WHITE);

    printf("------------------------------------------------------------\n");
    printf("%-22s | %-22s\n", "INSERTION SORT", "SHELL SORT");
    printf("------------------------------------------------------------\n");
    printf("%-22s | %-22s\n", "Simple algorithm", "Improved insertion sort");
    printf("%-22s | %-22s\n", "Nearby comparisons", "Gap-based comparisons");
    printf("%-22s | %-22s\n", "Sorted portion", "Multiple gap phases");
    printf("%-22s | %-22s\n", "Space: O(1)", "Space: O(1)");
    printf("%-22s | %-22s\n", "Stable", "Generally not stable");
    printf("------------------------------------------------------------\n");

    printf("\nKEY DIFFERENCE\n\n");

    printf("Insertion Sort mainly works with nearby elements.\n");
    printf("Shell Sort moves elements over larger distances first\n");
    printf("using decreasing GAP values.\n");

    pressEnter();
}

/* ============================================================
   LEARN MENU
   ============================================================ */

void learnAlgorithms()
{
    int choice;

    while (1)
    {
        clearScreen();
        showHeader();

        setColor(GREEN);
        printf("\n                  LEARN ALGORITHMS\n\n");

        setColor(WHITE);

        printf("   [1] Learn Insertion Sort\n");
        printf("   [2] Learn Shell Sort\n");
        printf("   [3] Compare the Concepts\n");
        printf("   [0] Back to Main Menu\n");

        setColor(YELLOW);
        printf("\n   Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                learnInsertionSort();
                break;

            case 2:
                learnShellSort();
                break;

            case 3:
                compareConcepts();
                break;

            case 0:
                return;

            default:
                setColor(RED);
                printf("\nInvalid choice!\n");
                pressEnter();
        }
    }
}

/* ============================================================
   PSEUDOCODE
   ============================================================ */

void showInsertionPseudocode()
{
    clearScreen();
    showHeader();

    setColor(GREEN);
    printf("\n             INSERTION SORT - PSEUDOCODE\n\n");

    setColor(WHITE);

    printf("for i = 1 to n - 1\n");
    printf("    key = A[i]\n");
    printf("    j = i - 1\n\n");

    printf("    while j >= 0 AND A[j] > key\n");
    printf("        A[j + 1] = A[j]\n");
    printf("        j = j - 1\n\n");

    printf("    A[j + 1] = key\n");

    printSeparator();

    printf("KEY VARIABLES\n\n");
    printf("i   -> Current element\n");
    printf("key -> Element being inserted\n");
    printf("j   -> Previous position\n");

    pressEnter();
}

void showShellPseudocode()
{
    clearScreen();
    showHeader();

    setColor(GREEN);
    printf("\n                SHELL SORT - PSEUDOCODE\n\n");

    setColor(WHITE);

    printf("gap = n / 2\n\n");

    printf("while gap > 0\n");
    printf("    for i = gap to n - 1\n");
    printf("        temp = A[i]\n");
    printf("        j = i\n\n");

    printf("        while j >= gap AND A[j-gap] > temp\n");
    printf("            A[j] = A[j-gap]\n");
    printf("            j = j - gap\n\n");

    printf("        A[j] = temp\n\n");
    printf("    gap = gap / 2\n");

    printSeparator();

    printf("KEY VARIABLES\n\n");
    printf("gap  -> Distance between elements\n");
    printf("temp -> Current element\n");
    printf("j    -> Current position\n");

    pressEnter();
}

void showAlgorithmSteps()
{
    clearScreen();
    showHeader();

    setColor(GREEN);
    printf("\n                  ALGORITHM STEPS\n\n");

    setColor(YELLOW);
    printf("INSERTION SORT\n\n");

    setColor(WHITE);

    printf("1. Select the KEY.\n");
    printf("2. Compare it with previous elements.\n");
    printf("3. Shift larger elements right.\n");
    printf("4. Insert KEY.\n");
    printf("5. Repeat.\n");

    printSeparator();

    setColor(YELLOW);
    printf("SHELL SORT\n\n");

    setColor(WHITE);

    printf("1. Select a GAP.\n");
    printf("2. Compare gap-separated elements.\n");
    printf("3. Shift elements when necessary.\n");
    printf("4. Reduce GAP.\n");
    printf("5. Repeat until GAP = 1.\n");

    pressEnter();
}

void pseudocodeMenu()
{
    int choice;

    while (1)
    {
        clearScreen();
        showHeader();

        setColor(GREEN);
        printf("\n                    PSEUDOCODE\n\n");

        setColor(WHITE);

        printf("   [1] Insertion Sort Pseudocode\n");
        printf("   [2] Shell Sort Pseudocode\n");
        printf("   [3] Algorithm Steps\n");
        printf("   [0] Back to Main Menu\n");

        setColor(YELLOW);
        printf("\n   Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                showInsertionPseudocode();
                break;

            case 2:
                showShellPseudocode();
                break;

            case 3:
                showAlgorithmSteps();
                break;

            case 0:
                return;

            default:
                setColor(RED);
                printf("\nInvalid choice!\n");
                pressEnter();
        }
    }
}

/* ============================================================
   INSERTION SORT PERFORMANCE
   ============================================================ */

void insertionSortPerformance(
    int arr[],
    int n,
    long long *comparisons,
    long long *shifts)
{
    *comparisons = 0;
    *shifts = 0;

    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0)
        {
            (*comparisons)++;

            if (arr[j] > key)
            {
                arr[j + 1] = arr[j];
                (*shifts)++;
                j--;
            }
            else
            {
                break;
            }
        }

        arr[j + 1] = key;
    }
}

/* ============================================================
   INTERACTIVE INSERTION SORT
   ============================================================ */

void displayInsertionStep(
    int arr[],
    int n,
    int pass,
    int key,
    long long comparisons,
    long long shifts)
{
    clearScreen();
    showHeader();

    setColor(GREEN);
    printf("\n               INSERTION SORT - LIVE\n\n");

    setColor(YELLOW);
    printf("PASS %d\n\n", pass);

    setColor(WHITE);

    printf("Current Array:\n");
    printArray(arr, n);

    printf("\nKEY           : %d\n", key);
    printf("Comparisons   : %lld\n", comparisons);
    printf("Shifts        : %lld\n", shifts);

    printSeparator();
}

void tryInsertionSort()
{
    int arr[MAX_SIZE];
    int original[MAX_SIZE];
    int n;

    long long comparisons = 0;
    long long shifts = 0;

    clock_t startTime;
    clock_t endTime;

    clearScreen();
    showHeader();

    setColor(GREEN);
    printf("\n               TRY INSERTION SORT\n\n");

    setColor(WHITE);

    printf("Enter number of elements (1-%d): ", MAX_SIZE);
    scanf("%d", &n);

    if (n < 1 || n > MAX_SIZE)
    {
        setColor(RED);
        printf("\nInvalid size!\n");
        pressEnter();
        return;
    }

    printf("\nEnter %d elements:\n\n", n);

    for (int i = 0; i < n; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
        original[i] = arr[i];
    }

    printf("\nOriginal Array: ");
    printArray(original, n);

    Sleep(800);

    startTime = clock();

    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        displayInsertionStep(
            arr,
            n,
            i,
            key,
            comparisons,
            shifts
        );

        setColor(YELLOW);
        printf("\nKEY = %d\n\n", key);
        setColor(WHITE);

        while (j >= 0)
        {
            comparisons++;

            printf("Comparing %d with %d\n", arr[j], key);

            if (arr[j] > key)
            {
                printf("%d > %d -> SHIFT\n",
                       arr[j], key);

                arr[j + 1] = arr[j];
                shifts++;
                j--;

                printf("Array after shift: ");
                printArray(arr, n);

                Sleep(400);
            }
            else
            {
                printf("%d <= %d -> NO SHIFT\n",
                       arr[j], key);
                break;
            }
        }

        arr[j + 1] = key;

        printf("\nAfter Pass %d: ", i);
        printArray(arr, n);

        setColor(YELLOW);
        printf("\nPress Enter for next pass...");
        getchar();
        getchar();
    }

    endTime = clock();

    double elapsed =
        ((double)(endTime - startTime) /
        CLOCKS_PER_SEC) * 1000.0;

    clearScreen();
    showHeader();

    setColor(GREEN);
    printf("\n                SORTING COMPLETE!\n\n");

    setColor(WHITE);

    printf("Original Array : ");
    printArray(original, n);

    printf("Sorted Array   : ");
    printArray(arr, n);

    printSeparator();

    printf("PERFORMANCE ANALYSIS\n\n");

    printf("Elements           : %d\n", n);
    printf("Comparisons        : %lld\n", comparisons);
    printf("Shifts             : %lld\n", shifts);
    printf("Execution Time     : %.3f ms\n", elapsed);

    printf("\nBest Case          : O(n)\n");
    printf("Average Case       : O(n^2)\n");
    printf("Worst Case         : O(n^2)\n");
    printf("Space Complexity   : O(1)\n");

    setColor(GREEN);
    printf("\nInsertion Sort completed successfully!\n");

    pressEnter();
}

/* ============================================================
   SHELL SORT PERFORMANCE
   ============================================================ */

void shellSortPerformance(
    int arr[],
    int n,
    long long *comparisons,
    long long *shifts)
{
    *comparisons = 0;
    *shifts = 0;

    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j = i;

            while (j >= gap)
            {
                (*comparisons)++;

                if (arr[j - gap] > temp)
                {
                    arr[j] = arr[j - gap];
                    (*shifts)++;
                    j -= gap;
                }
                else
                {
                    break;
                }
            }

            arr[j] = temp;
        }
    }
}

/* ============================================================
   DISPLAY SHELL SORT STEP
   ============================================================ */

void displayShellStep(
    int arr[],
    int n,
    int gap,
    int currentIndex,
    int temp,
    long long comparisons,
    long long shifts)
{
    clearScreen();
    showHeader();

    setColor(MAGENTA);
    printf("\n                 SHELL SORT - LIVE\n\n");

    setColor(YELLOW);
    printf("CURRENT GAP : %d\n\n", gap);

    setColor(WHITE);

    printf("Current Array:\n");
    printArray(arr, n);

    printf("\nCurrent Index : %d\n", currentIndex);
    printf("Current Value : %d\n", temp);

    printf("\nComparisons   : %lld\n", comparisons);
    printf("Shifts        : %lld\n", shifts);

    printSeparator();
}

/* ============================================================
   INTERACTIVE SHELL SORT
   ============================================================ */

void tryShellSort()
{
    int arr[MAX_SIZE];
    int original[MAX_SIZE];

    int n;

    long long comparisons = 0;
    long long shifts = 0;

    clock_t startTime;
    clock_t endTime;

    clearScreen();
    showHeader();

    setColor(MAGENTA);
    printf("\n                  TRY SHELL SORT\n\n");

    setColor(WHITE);

    printf("Enter number of elements (1-%d): ", MAX_SIZE);
    scanf("%d", &n);

    if (n < 1 || n > MAX_SIZE)
    {
        setColor(RED);
        printf("\nInvalid size!\n");
        pressEnter();
        return;
    }

    printf("\nEnter %d elements:\n\n", n);

    for (int i = 0; i < n; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);

        original[i] = arr[i];
    }

    clearScreen();
    showHeader();

    setColor(YELLOW);
    printf("\n                    INPUT ARRAY\n\n");

    setColor(WHITE);

    printf("Original Array:\n");
    printArray(original, n);

    printf("\nShell Sort uses decreasing GAP values.\n");

    Sleep(1000);

    startTime = clock();

    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        clearScreen();
        showHeader();

        setColor(MAGENTA);
        printf("\n                  GAP PHASE: %d\n\n", gap);

        setColor(WHITE);

        printf("Array before this GAP phase:\n");
        printArray(arr, n);

        printf("\nElements separated by %d positions are compared.\n",
               gap);

        Sleep(1000);

        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j = i;

            displayShellStep(
                arr,
                n,
                gap,
                i,
                temp,
                comparisons,
                shifts
            );

            setColor(YELLOW);
            printf("\nComparing positions %d and %d\n",
                   j - gap, j);

            setColor(WHITE);

            while (j >= gap)
            {
                comparisons++;

                printf("\nCompare %d and %d\n",
                       arr[j - gap], temp);

                if (arr[j - gap] > temp)
                {
                    printf("%d > %d -> SHIFT\n",
                           arr[j - gap], temp);

                    arr[j] = arr[j - gap];

                    shifts++;

                    j -= gap;

                    printf("Array after shift:\n");
                    printArray(arr, n);

                    Sleep(400);
                }
                else
                {
                    printf("%d <= %d -> NO SHIFT\n",
                           arr[j - gap], temp);
                    break;
                }
            }

            arr[j] = temp;

            printf("\nInsert %d at position %d\n",
                   temp, j);

            printf("Current Array:\n");
            printArray(arr, n);

            setColor(YELLOW);
            printf("\nPress Enter for next step...");
            getchar();
            getchar();
        }

        clearScreen();
        showHeader();

        setColor(GREEN);
        printf("\n              GAP %d PHASE COMPLETE\n\n", gap);

        setColor(WHITE);

        printf("Array after GAP %d:\n\n", gap);
        printArray(arr, n);

        printf("\nComparisons : %lld\n", comparisons);
        printf("Shifts      : %lld\n", shifts);

        if (gap / 2 > 0)
        {
            printf("\nNext GAP = %d\n", gap / 2);
        }
        else
        {
            printf("\nNext GAP = 0 -> Sorting complete\n");
        }

        printSeparator();

        setColor(YELLOW);
        printf("\nPress Enter to continue...");
        getchar();
        getchar();
    }

    endTime = clock();

    double elapsed =
        ((double)(endTime - startTime) /
        CLOCKS_PER_SEC) * 1000.0;

    clearScreen();
    showHeader();

    setColor(GREEN);
    printf("\n                SHELL SORT COMPLETE!\n\n");

    setColor(WHITE);

    printf("Original Array : ");
    printArray(original, n);

    printf("Sorted Array   : ");
    printArray(arr, n);

    printSeparator();

    setColor(YELLOW);
    printf("PERFORMANCE ANALYSIS\n\n");

    setColor(WHITE);

    printf("Elements           : %d\n", n);
    printf("Comparisons        : %lld\n", comparisons);
    printf("Shifts             : %lld\n", shifts);
    printf("Execution Time     : %.3f ms\n", elapsed);

    printf("\nSpace Complexity   : O(1)\n");

    printf("\nTime Complexity:\n");
    printf("Depends on the GAP sequence used.\n");

    setColor(GREEN);
    printf("\nShell Sort completed successfully!\n");

    pressEnter();
}

/* ============================================================
   ALGORITHM COMPARISON
   ============================================================ */

void compareAlgorithms()
{
    int original[MAX_SIZE];
    int insertionArray[MAX_SIZE];
    int shellArray[MAX_SIZE];

    int n;

    long long insertionComparisons;
    long long insertionShifts;

    long long shellComparisons;
    long long shellShifts;

    clock_t insertionStart;
    clock_t insertionEnd;

    clock_t shellStart;
    clock_t shellEnd;

    double insertionTime;
    double shellTime;

    clearScreen();
    showHeader();

    setColor(GREEN);
    printf("\n                ALGORITHM COMPARISON\n\n");

    setColor(WHITE);

    printf("Both algorithms will use the SAME input array.\n\n");

    printf("Enter number of elements (1-%d): ", MAX_SIZE);
    scanf("%d", &n);

    if (n < 1 || n > MAX_SIZE)
    {
        setColor(RED);
        printf("\nInvalid size!\n");
        pressEnter();
        return;
    }

    printf("\nEnter %d elements:\n\n", n);

    for (int i = 0; i < n; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &original[i]);

        insertionArray[i] = original[i];
        shellArray[i] = original[i];
    }

    clearScreen();
    showHeader();

    setColor(YELLOW);
    printf("\n                    INPUT DATA\n\n");

    setColor(WHITE);

    printf("Original Array: ");
    printArray(original, n);

    printSeparator();

    printf("\nRunning Insertion Sort...\n");

    insertionStart = clock();

    insertionSortPerformance(
        insertionArray,
        n,
        &insertionComparisons,
        &insertionShifts
    );

    insertionEnd = clock();

    insertionTime =
        ((double)(insertionEnd - insertionStart)
        / CLOCKS_PER_SEC) * 1000.0;

    printf("Insertion Sort completed.\n");

    printf("\nRunning Shell Sort...\n");

    shellStart = clock();

    shellSortPerformance(
        shellArray,
        n,
        &shellComparisons,
        &shellShifts
    );

    shellEnd = clock();

    shellTime =
        ((double)(shellEnd - shellStart)
        / CLOCKS_PER_SEC) * 1000.0;

    printf("Shell Sort completed.\n");

    Sleep(700);

    clearScreen();
    showHeader();

    setColor(GREEN);
    printf("\n                 COMPARISON RESULTS\n\n");

    setColor(WHITE);

    printf("INPUT ARRAY\n");
    printf("-----------\n");
    printArray(original, n);

    printSeparator();

    printf("\nINSERTION SORT\n\n");

    printf("Sorted Array : ");
    printArray(insertionArray, n);

    printf("Comparisons  : %lld\n", insertionComparisons);
    printf("Shifts       : %lld\n", insertionShifts);
    printf("Time         : %.3f ms\n", insertionTime);

    printSeparator();

    printf("\nSHELL SORT\n\n");

    printf("Sorted Array : ");
    printArray(shellArray, n);

    printf("Comparisons  : %lld\n", shellComparisons);
    printf("Shifts       : %lld\n", shellShifts);
    printf("Time         : %.3f ms\n", shellTime);

    printSeparator();

    setColor(YELLOW);
    printf("\n                 PERFORMANCE TABLE\n\n");

    setColor(WHITE);

    printf("------------------------------------------------------------\n");
    printf("%-20s | %-14s | %-14s\n",
           "Metric",
           "Insertion",
           "Shell");
    printf("------------------------------------------------------------\n");

    printf("%-20s | %-14lld | %-14lld\n",
           "Comparisons",
           insertionComparisons,
           shellComparisons);

    printf("%-20s | %-14lld | %-14lld\n",
           "Shifts",
           insertionShifts,
           shellShifts);

    printf("%-20s | %-14.3f | %-14.3f\n",
           "Time (ms)",
           insertionTime,
           shellTime);

    printf("------------------------------------------------------------\n");

    printSeparator();

    printf("\nWHAT DID WE LEARN?\n\n");

    printf("Insertion Sort builds the sorted portion gradually.\n");
    printf("Shell Sort first moves elements over larger distances\n");
    printf("using decreasing GAP values.\n");

    printf("\nBoth algorithms produced the same sorted result.\n");

    setColor(GREEN);
    printf("\nSORTLAB comparison completed successfully!\n");

    pressEnter();
}

/* ============================================================
   COMPLEXITY ANALYSIS
   ============================================================ */

void complexityAnalysis()
{
    clearScreen();
    showHeader();

    setColor(GREEN);
    printf("\n                 COMPLEXITY ANALYSIS\n\n");

    setColor(WHITE);

    printf("============================================================\n");
    printf("                  INSERTION SORT\n");
    printf("============================================================\n\n");

    printf("Best Case       : O(n)\n");
    printf("Average Case    : O(n^2)\n");
    printf("Worst Case      : O(n^2)\n");
    printf("Space           : O(1)\n");
    printf("Stable          : Yes\n");
    printf("In-place        : Yes\n");

    printf("\n============================================================\n");
    printf("                     SHELL SORT\n");
    printf("============================================================\n\n");

    printf("Best/Average/Worst time depends on the GAP sequence.\n");
    printf("Space           : O(1)\n");
    printf("Stable          : Generally No\n");
    printf("In-place        : Yes\n");

    printf("\n============================================================\n");

    setColor(YELLOW);
    printf("\nIMPORTANT:\n\n");

    setColor(WHITE);

    printf("Shell Sort does not have one universal time complexity.\n");
    printf("Its performance changes according to the GAP sequence.\n");

    pressEnter();
}

/* ============================================================
   C IMPLEMENTATION
   ============================================================ */

void showCImplementation()
{
    clearScreen();
    showHeader();

    setColor(GREEN);
    printf("\n                  C IMPLEMENTATION\n\n");

    setColor(WHITE);

    printf("The SortLab algorithms are implemented in C.\n\n");

    printf("Main techniques used:\n\n");

    printf("1. Arrays\n");
    printf("2. Loops\n");
    printf("3. Functions\n");
    printf("4. Pointers for performance counters\n");
    printf("5. Conditional statements\n");
    printf("6. clock() for execution time\n");
    printf("7. Windows console colors\n");

    printSeparator();

    printf("\nMain algorithm functions:\n\n");

    setColor(YELLOW);
    printf("insertionSortPerformance()\n");
    printf("tryInsertionSort()\n");
    printf("shellSortPerformance()\n");
    printf("tryShellSort()\n");
    printf("compareAlgorithms()\n");

    setColor(WHITE);

    pressEnter();
}

/* ============================================================
   MAIN MENU
   ============================================================ */

int main()
{
    int choice;

    while (1)
    {
        clearScreen();
        showHeader();

        setColor(GREEN);
        printf("\n                    MAIN MENU\n\n");

        setColor(WHITE);

        printf("   [1] Learn Algorithms\n");
        printf("   [2] View Pseudocode\n");
        printf("   [3] Try Insertion Sort\n");
        printf("   [4] Try Shell Sort\n");
        printf("   [5] Compare Algorithms\n");
        printf("   [6] Complexity Analysis\n");
        printf("   [7] C Implementation\n");
        printf("   [0] Exit\n");

        setColor(CYAN);
        printf("\n------------------------------------------------------------\n");

        setColor(YELLOW);
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                learnAlgorithms();
                break;

            case 2:
                pseudocodeMenu();
                break;

            case 3:
                tryInsertionSort();
                break;

            case 4:
                tryShellSort();
                break;

            case 5:
                compareAlgorithms();
                break;

            case 6:
                complexityAnalysis();
                break;

            case 7:
                showCImplementation();
                break;

            case 0:
                clearScreen();

                setColor(CYAN);
                printf("\n============================================================\n");

                setColor(GREEN);
                printf("              Thank you for using SORTLAB!\n");

                setColor(CYAN);
                printf("============================================================\n\n");

                setColor(WHITE);

                return 0;

            default:
                setColor(RED);
                printf("\nInvalid choice!\n");
                pressEnter();
        }
    }

    return 0;
}