/* =========================================================
   SORTLAB - COMPLETE JAVASCRIPT
   Insertion Sort + Shell Sort
   Interactive Array-Box Visualization
   ========================================================= */


/* =========================================================
   GLOBAL VARIABLES
   ========================================================= */

let currentAlgorithm = "insertion";

let originalArray = [];

let sortingSteps = [];

let currentStep = 0;

let autoPlayTimer = null;

let comparisonCount = 0;

let shiftCount = 0;


/* =========================================================
   PAGE NAVIGATION
   ========================================================= */

function showSection(sectionId, clickedButton = null) {

    const sections =
        document.querySelectorAll(".page-section");

    sections.forEach(section => {
        section.classList.remove("active");
    });

    const selectedSection =
        document.getElementById(sectionId);

    if (selectedSection) {
        selectedSection.classList.add("active");
    }


    const navItems =
        document.querySelectorAll(".nav-item");

    navItems.forEach(item => {
        item.classList.remove("active");
    });


    if (clickedButton) {
        clickedButton.classList.add("active");
    }
    else {

        navItems.forEach(item => {

            const text =
                item.textContent.toLowerCase();

            if (
                (sectionId === "dashboard" &&
                    text.includes("dashboard")) ||

                (sectionId === "learn" &&
                    text.includes("learn")) ||

                (sectionId === "visualizer" &&
                    text.includes("visualizer")) ||

                (sectionId === "compare" &&
                    text.includes("compare")) ||

                (sectionId === "pseudocode" &&
                    text.includes("pseudocode")) ||

                (sectionId === "complexity" &&
                    text.includes("complexity")) ||

                (sectionId === "implementation" &&
                    text.includes("implementation"))
            ) {
                item.classList.add("active");
            }

        });

    }


    const titles = {

        dashboard:
            "Sorting Algorithm Laboratory",

        learn:
            "Learn Sorting Algorithms",

        visualizer:
            "Interactive Sorting Visualizer",

        compare:
            "Algorithm Comparison",

        pseudocode:
            "Sorting Algorithm Pseudocode",

        complexity:
            "Complexity Analysis",

        implementation:
            "C Implementation"

    };


    const pageTitle =
        document.getElementById("pageTitle");

    if (pageTitle) {
        pageTitle.textContent =
            titles[sectionId] ||
            "Sorting Algorithm Laboratory";
    }


    window.scrollTo({
        top: 0,
        behavior: "smooth"
    });
}


/* =========================================================
   OPEN VISUALIZER
   ========================================================= */

function openVisualizer() {

    showSection("visualizer");

    startVisualization();
}


/* =========================================================
   START SPECIFIC ALGORITHM
   ========================================================= */

function startAlgorithm(algorithm) {

    currentAlgorithm =
        algorithm === "shell"
            ? "shell"
            : "insertion";


    const select =
        document.getElementById("algorithmSelect");

    if (select) {
        select.value = currentAlgorithm;
    }


    showSection("visualizer");


    startVisualization();
}


/* =========================================================
   READ ARRAY
   ========================================================= */

function getInputArray() {

    const input =
        document.getElementById("arrayInput");

    if (!input) {
        return [];
    }


    const value =
        input.value.trim();


    if (!value) {
        return [];
    }


    const parts =
        value.split(/[\s,]+/);


    const numbers = [];


    for (const part of parts) {

        if (part === "") {
            continue;
        }


        const number =
            Number(part);


        if (!Number.isFinite(number)) {
            return [];
        }


        numbers.push(number);
    }


    return numbers.slice(0, 30);
}


/* =========================================================
   UPDATE VISUALIZER INFO
   ========================================================= */

function updateVisualizerInfo() {

    const algorithmElement =
        document.getElementById("currentAlgorithm");

    const stepElement =
        document.getElementById("stepCounter");

    const comparisonElement =
        document.getElementById("comparisonCounter");

    const shiftElement =
        document.getElementById("shiftCounter");


    if (algorithmElement) {

        algorithmElement.textContent =
            currentAlgorithm === "insertion"
                ? "Insertion Sort"
                : "Shell Sort";

    }


    if (stepElement) {

        stepElement.textContent =
            sortingSteps.length === 0
                ? "0 / 0"
                : `${currentStep + 1} / ${sortingSteps.length}`;

    }


    if (comparisonElement) {
        comparisonElement.textContent =
            comparisonCount;
    }


    if (shiftElement) {
        shiftElement.textContent =
            shiftCount;
    }
}


/* =========================================================
   RENDER ARRAY BOXES
   ========================================================= */

function renderArray(
    array,
    currentIndex = -1,
    compareIndices = [],
    shiftedIndices = [],
    sortedIndices = [],
    labels = {}
) {

    const container =
        document.getElementById("barsContainer");


    if (!container) {
        return;
    }


    container.innerHTML = "";


    array.forEach((value, index) => {

        const item =
            document.createElement("div");

        item.className =
            "array-item";


        const indexLabel =
            document.createElement("div");

        indexLabel.className =
            "array-index";

        indexLabel.textContent =
            `[${index}]`;


        const box =
            document.createElement("div");

        box.className =
            "array-box";

        box.textContent =
            value;


        const itemLabel =
            document.createElement("div");

        itemLabel.className =
            "array-item-label";

        itemLabel.textContent =
            labels[index] || "";


        if (index === currentIndex) {

            item.classList.add("current");

        }


        if (compareIndices.includes(index)) {

            item.classList.add("compare");

        }


        if (shiftedIndices.includes(index)) {

            item.classList.add("shifted");

        }


        if (sortedIndices.includes(index)) {

            item.classList.add("sorted");

        }


        item.appendChild(indexLabel);

        item.appendChild(box);

        item.appendChild(itemLabel);

        container.appendChild(item);

    });

}


/* =========================================================
   CREATE INSERTION SORT STEPS
   ========================================================= */

function createInsertionSortSteps(array) {

    const arr =
        [...array];


    const steps = [];


    let comparisons = 0;

    let shifts = 0;


    for (let i = 1; i < arr.length; i++) {

        const key =
            arr[i];

        let j =
            i - 1;


        steps.push({

            array: [...arr],

            currentIndex: i,

            compareIndices: [],

            shiftedIndices: [],

            sortedIndices:
                Array.from(
                    { length: i },
                    (_, index) => index
                ),

            comparisons,

            shifts,

            message:
                `Pass ${i}: Select ${key} as the key element.`,

            key,

            gap: null

        });


        while (j >= 0) {

            comparisons++;


            steps.push({

                array: [...arr],

                currentIndex: j + 1,

                compareIndices: [j, j + 1],

                shiftedIndices: [],

                sortedIndices:
                    Array.from(
                        { length: i },
                        (_, index) => index
                    ),

                comparisons,

                shifts,

                message:
                    `${arr[j]} is compared with key ${key}.`,

                key,

                gap: null

            });


            if (arr[j] <= key) {

                steps.push({

                    array: [...arr],

                    currentIndex: j + 1,

                    compareIndices: [j, j + 1],

                    shiftedIndices: [],

                    sortedIndices:
                        Array.from(
                            { length: i },
                            (_, index) => index
                        ),

                    comparisons,

                    shifts,

                    message:
                        `${arr[j]} is already smaller than or equal to ${key}. No shift is needed.`,

                    key,

                    gap: null

                });

                break;
            }


            arr[j + 1] =
                arr[j];


            shifts++;


            steps.push({

                array: [...arr],

                currentIndex: j,

                compareIndices: [],

                shiftedIndices: [j, j + 1],

                sortedIndices:
                    Array.from(
                        { length: i },
                        (_, index) => index
                    ),

                comparisons,

                shifts,

                message:
                    `${arr[j + 1]} is shifted one position to the right.`,

                key,

                gap: null

            });


            j--;

        }


        arr[j + 1] =
            key;


        steps.push({

            array: [...arr],

            currentIndex: j + 1,

            compareIndices: [],

            shiftedIndices: [],

            sortedIndices:
                Array.from(
                    { length: i + 1 },
                    (_, index) => index
                ),

            comparisons,

            shifts,

            message:
                `Insert ${key} at position ${j + 1}. Pass ${i} completed.`,

            key,

            gap: null

        });

    }


    steps.push({

        array: [...arr],

        currentIndex: -1,

        compareIndices: [],

        shiftedIndices: [],

        sortedIndices:
            Array.from(
                { length: arr.length },
                (_, index) => index
            ),

        comparisons,

        shifts,

        message:
            "Insertion Sort completed successfully.",

        key: null,

        gap: null

    });


    return steps;
}


/* =========================================================
   CREATE SHELL SORT STEPS
   ========================================================= */

function createShellSortSteps(array) {

    const arr =
        [...array];


    const steps = [];


    let comparisons = 0;

    let shifts = 0;


    for (
        let gap = Math.floor(arr.length / 2);
        gap > 0;
        gap = Math.floor(gap / 2)
    ) {

        steps.push({

            array: [...arr],

            currentIndex: -1,

            compareIndices: [],

            shiftedIndices: [],

            sortedIndices: [],

            comparisons,

            shifts,

            message:
                `Starting Shell Sort phase with gap ${gap}.`,

            key: null,

            gap

        });


        for (
            let i = gap;
            i < arr.length;
            i++
        ) {

            const temp =
                arr[i];

            let j =
                i;


            steps.push({

                array: [...arr],

                currentIndex: i,

                compareIndices: [],

                shiftedIndices: [],

                sortedIndices: [],

                comparisons,

                shifts,

                message:
                    `Select ${temp} and compare elements ${gap} positions apart.`,

                key: temp,

                gap

            });


            while (j >= gap) {

                comparisons++;


                steps.push({

                    array: [...arr],

                    currentIndex: j,

                    compareIndices: [j, j - gap],

                    shiftedIndices: [],

                    sortedIndices: [],

                    comparisons,

                    shifts,

                    message:
                        `${arr[j - gap]} is compared with ${temp} using gap ${gap}.`,

                    key: temp,

                    gap

                });


                if (arr[j - gap] <= temp) {

                    break;

                }


                arr[j] =
                    arr[j - gap];


                shifts++;


                steps.push({

                    array: [...arr],

                    currentIndex: j,

                    compareIndices: [],

                    shiftedIndices: [j, j - gap],

                    sortedIndices: [],

                    comparisons,

                    shifts,

                    message:
                        `${arr[j]} is shifted to position ${j}.`,

                    key: temp,

                    gap

                });


                j -= gap;

            }


            arr[j] =
                temp;


            steps.push({

                array: [...arr],

                currentIndex: j,

                compareIndices: [],

                shiftedIndices: [],

                sortedIndices: [],

                comparisons,

                shifts,

                message:
                    `${temp} is inserted at position ${j}.`,

                key: temp,

                gap

            });

        }

    }


    steps.push({

        array: [...arr],

        currentIndex: -1,

        compareIndices: [],

        shiftedIndices: [],

        sortedIndices:
            Array.from(
                { length: arr.length },
                (_, index) => index
            ),

        comparisons,

        shifts,

        message:
            "Shell Sort completed successfully.",

        key: null,

        gap: 0

    });


    return steps;
}


/* =========================================================
   START VISUALIZATION
   ========================================================= */

function startVisualization() {

    stopAutoPlay();


    const select =
        document.getElementById("algorithmSelect");


    if (select) {

        currentAlgorithm =
            select.value === "shell"
                ? "shell"
                : "insertion";

    }


    const array =
        getInputArray();


    if (
        array.length < 2 ||
        array.length > 30
    ) {

        showVisualizerMessage(
            "Please enter between 2 and 30 valid numbers."
        );

        return;
    }


    originalArray =
        [...array];


    if (currentAlgorithm === "insertion") {

        sortingSteps =
            createInsertionSortSteps(array);

    }
    else {

        sortingSteps =
            createShellSortSteps(array);

    }


    currentStep = 0;


    comparisonCount = 0;

    shiftCount = 0;


    displayStep();

}


/* =========================================================
   DISPLAY CURRENT STEP
   ========================================================= */

function displayStep() {

    if (
        sortingSteps.length === 0
    ) {

        renderArray(originalArray);

        updateVisualizerInfo();

        return;

    }


    const step =
        sortingSteps[currentStep];


    if (!step) {
        return;
    }


    comparisonCount =
        step.comparisons;

    shiftCount =
        step.shifts;


    renderArray(

        step.array,

        step.currentIndex,

        step.compareIndices,

        step.shiftedIndices,

        step.sortedIndices,

        createLabels(step)

    );


    updateVisualizerInfo();


    const message =
        step.message ||
        "Sorting in progress.";


    showVisualizerMessage(message);


    const gapDisplay =
        document.getElementById("gapDisplay");


    if (gapDisplay) {

        if (
            currentAlgorithm === "shell" &&
            step.gap
        ) {

            gapDisplay.textContent =
                `Gap: ${step.gap}`;

        }
        else {

            gapDisplay.textContent =
                "Gap: —";

        }

    }

}


/* =========================================================
   CREATE ARRAY LABELS
   ========================================================= */

function createLabels(step) {

    const labels = {};


    if (
        currentAlgorithm === "insertion" &&
        step.currentIndex >= 0
    ) {

        labels[step.currentIndex] =
            "CURRENT";

    }


    if (
        step.key !== null &&
        step.currentIndex >= 0
    ) {

        labels[step.currentIndex] =
            `KEY: ${step.key}`;

    }


    step.compareIndices.forEach(index => {

        if (!labels[index]) {

            labels[index] =
                "COMPARE";

        }

    });


    step.shiftedIndices.forEach(index => {

        labels[index] =
            "SHIFT";

    });


    step.sortedIndices.forEach(index => {

        if (!labels[index]) {

            labels[index] =
                "SORTED";

        }

    });


    return labels;
}


/* =========================================================
   VISUALIZER MESSAGE
   ========================================================= */

function showVisualizerMessage(message) {

    const element =
        document.getElementById(
            "visualizerMessage"
        );


    if (element) {

        element.textContent =
            message;

    }

}


/* =========================================================
   NEXT STEP
   ========================================================= */

function nextStep() {

    if (
        sortingSteps.length === 0
    ) {

        startVisualization();

        return;

    }


    if (
        currentStep <
        sortingSteps.length - 1
    ) {

        currentStep++;

        displayStep();

    }
    else {

        showVisualizerMessage(
            "Sorting is already complete. Press Reset to start again."
        );

        stopAutoPlay();

    }

}


/* =========================================================
   PREVIOUS STEP
   ========================================================= */

function previousStep() {

    stopAutoPlay();


    if (
        sortingSteps.length === 0
    ) {

        return;

    }


    if (currentStep > 0) {

        currentStep--;

        displayStep();

    }
    else {

        showVisualizerMessage(
            "You are already at the first step."
        );

    }

}


/* =========================================================
   AUTO PLAY
   ========================================================= */

function autoPlay() {

    if (
        sortingSteps.length === 0
    ) {

        startVisualization();

        return;

    }


    stopAutoPlay();


    autoPlayTimer =
        setInterval(() => {

            if (
                currentStep >=
                sortingSteps.length - 1
            ) {

                stopAutoPlay();

                displayStep();

                return;

            }


            currentStep++;

            displayStep();

        }, 900);

}


/* =========================================================
   STOP AUTO PLAY
   ========================================================= */

function stopAutoPlay() {

    if (autoPlayTimer !== null) {

        clearInterval(autoPlayTimer);

        autoPlayTimer = null;

    }

}


/* =========================================================
   RESET VISUALIZER
   ========================================================= */

function resetVisualizer() {

    stopAutoPlay();


    currentStep = 0;

    comparisonCount = 0;

    shiftCount = 0;


    if (
        originalArray.length > 0
    ) {

        if (currentAlgorithm === "insertion") {

            sortingSteps =
                createInsertionSortSteps(
                    originalArray
                );

        }
        else {

            sortingSteps =
                createShellSortSteps(
                    originalArray
                );

        }


        displayStep();

        showVisualizerMessage(
            "Visualization reset to the beginning."
        );

    }
    else {

        const container =
            document.getElementById(
                "barsContainer"
            );


        if (container) {

            container.innerHTML =
                `<div class="empty-visualizer">
                    Click "Visualize" to begin
                </div>`;

        }


        updateVisualizerInfo();

    }

}


/* =========================================================
   MEASURE INSERTION SORT
   ========================================================= */

function measureInsertionSort(array) {

    const arr =
        [...array];


    let comparisons = 0;

    let shifts = 0;


    const start =
        performance.now();


    for (
        let i = 1;
        i < arr.length;
        i++
    ) {

        const key =
            arr[i];

        let j =
            i - 1;


        while (j >= 0) {

            comparisons++;


            if (arr[j] <= key) {

                break;

            }


            arr[j + 1] =
                arr[j];


            shifts++;

            j--;

        }


        arr[j + 1] =
            key;

    }


    const end =
        performance.now();


    return {

        array: arr,

        comparisons,

        shifts,

        time: end - start

    };

}


/* =========================================================
   MEASURE SHELL SORT
   ========================================================= */

function measureShellSort(array) {

    const arr =
        [...array];


    let comparisons = 0;

    let shifts = 0;


    const start =
        performance.now();


    for (
        let gap = Math.floor(arr.length / 2);
        gap > 0;
        gap = Math.floor(gap / 2)
    ) {

        for (
            let i = gap;
            i < arr.length;
            i++
        ) {

            const temp =
                arr[i];

            let j =
                i;


            while (j >= gap) {

                comparisons++;


                if (
                    arr[j - gap] <= temp
                ) {

                    break;

                }


                arr[j] =
                    arr[j - gap];


                shifts++;

                j -= gap;

            }


            arr[j] =
                temp;

        }

    }


    const end =
        performance.now();


    return {

        array: arr,

        comparisons,

        shifts,

        time: end - start

    };

}


/* =========================================================
   RUN COMPARISON
   ========================================================= */

function runComparison() {

    const input =
        document.getElementById(
            "compareInput"
        );


    if (!input) {
        return;
    }


    const value =
        input.value.trim();


    const parts =
        value.split(/[\s,]+/);


    const array = [];


    for (const part of parts) {

        if (part === "") {
            continue;
        }


        const number =
            Number(part);


        if (!Number.isFinite(number)) {

            alert(
                "Please enter only valid numbers."
            );

            return;

        }


        array.push(number);

    }


    if (
        array.length < 2 ||
        array.length > 1000
    ) {

        alert(
            "Please enter between 2 and 1000 numbers."
        );

        return;

    }


    const insertion =
        measureInsertionSort(array);


    const shell =
        measureShellSort(array);


    displayComparisonArray(
        "insertionResult",
        insertion.array
    );


    displayComparisonArray(
        "shellResult",
        shell.array
    );


    setText(
        "insertionComparisons",
        insertion.comparisons
    );


    setText(
        "insertionShifts",
        insertion.shifts
    );


    setText(
        "insertionTime",
        formatTime(insertion.time)
    );


    setText(
        "shellComparisons",
        shell.comparisons
    );


    setText(
        "shellShifts",
        shell.shifts
    );


    setText(
        "shellTime",
        formatTime(shell.time)
    );


    displayFinalSortedArray(
        insertion.array
    );

}


/* =========================================================
   DISPLAY COMPARISON ARRAY
   ========================================================= */

function displayComparisonArray(
    elementId,
    array
) {

    const element =
        document.getElementById(
            elementId
        );


    if (!element) {
        return;
    }


    element.innerHTML = "";


    array.forEach(number => {

        const span =
            document.createElement("span");

        span.textContent =
            number;

        element.appendChild(span);

    });

}


/* =========================================================
   DISPLAY FINAL SORTED ARRAY
   ========================================================= */

function displayFinalSortedArray(array) {

    const container =
        document.getElementById(
            "comparisonSortedResult"
        );


    if (!container) {
        return;
    }


    container.innerHTML = "";


    array.forEach(number => {

        const span =
            document.createElement("span");

        span.textContent =
            number;

        container.appendChild(span);

    });

}


/* =========================================================
   FORMAT EXECUTION TIME
   ========================================================= */

function formatTime(time) {

    if (time < 0.01) {

        return "< 0.01 ms";

    }


    return `${time.toFixed(3)} ms`;

}


/* =========================================================
   SAFE TEXT UPDATE
   ========================================================= */

function setText(
    elementId,
    value
) {

    const element =
        document.getElementById(
            elementId
        );


    if (element) {

        element.textContent =
            value;

    }

}


/* =========================================================
   THEME
   ========================================================= */

function toggleTheme() {

    document.body.classList.toggle(
        "light-theme"
    );


    const isLight =
        document.body.classList.contains(
            "light-theme"
        );


    localStorage.setItem(
        "sortlabTheme",
        isLight
            ? "light"
            : "dark"
    );


    const icon =
        document.getElementById(
            "themeIcon"
        );


    const text =
        document.getElementById(
            "themeText"
        );


    if (icon) {

        icon.textContent =
            isLight
                ? "☀"
                : "☾";

    }


    if (text) {

        text.textContent =
            isLight
                ? "Light Mode"
                : "Dark Mode";

    }

}


/* =========================================================
   LOAD SAVED THEME
   ========================================================= */

function loadTheme() {

    const theme =
        localStorage.getItem(
            "sortlabTheme"
        );


    if (theme === "light") {

        document.body.classList.add(
            "light-theme"
        );


        const icon =
            document.getElementById(
                "themeIcon"
            );


        const text =
            document.getElementById(
                "themeText"
            );


        if (icon) {
            icon.textContent = "☀";
        }


        if (text) {
            text.textContent =
                "Light Mode";
        }

    }

}


/* =========================================================
   SHOW C CODE TABS
   ========================================================= */

function showCode(
    codeId,
    clickedButton
) {

    const codeBlocks =
        document.querySelectorAll(
            ".implementation-code"
        );


    codeBlocks.forEach(block => {

        block.classList.remove(
            "active"
        );

    });


    const selected =
        document.getElementById(
            codeId
        );


    if (selected) {

        selected.classList.add(
            "active"
        );

    }


    const tabs =
        document.querySelectorAll(
            ".implementation-tab"
        );


    tabs.forEach(tab => {

        tab.classList.remove(
            "active"
        );

    });


    if (clickedButton) {

        clickedButton.classList.add(
            "active"
        );

    }

}


/* =========================================================
   KEYBOARD CONTROLS
   ========================================================= */

document.addEventListener(
    "keydown",
    event => {

        const visualizer =
            document.getElementById(
                "visualizer"
            );


        if (
            !visualizer ||
            !visualizer.classList.contains(
                "active"
            )
        ) {

            return;

        }


        if (
            event.key === "ArrowRight"
        ) {

            nextStep();

        }


        if (
            event.key === "ArrowLeft"
        ) {

            previousStep();

        }


        if (
            event.key === " "
        ) {

            event.preventDefault();

            autoPlay();

        }

    }
);


/* =========================================================
   INITIALIZATION
   ========================================================= */

document.addEventListener(
    "DOMContentLoaded",
    () => {

        loadTheme();


        const select =
            document.getElementById(
                "algorithmSelect"
            );


        if (select) {

            select.addEventListener(
                "change",
                () => {

                    currentAlgorithm =
                        select.value === "shell"
                            ? "shell"
                            : "insertion";

                }
            );

        }


        console.log(
            "SortLab initialized successfully."
        );

    }
);