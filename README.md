# 🏨 College Hostel Room Allocation System

A menu-driven **College Hostel Room Allocation System developed using C programming**, designed to manage student records, hostel rooms, room allocation, and vacancy details. The project also includes a read-only web dashboard developed using Python Flask to visualize hostel occupancy and room availability.

## 📌 Project Overview

Managing hostel rooms manually can be time-consuming and difficult. This project provides a simple computerized solution to maintain student information, organize hostel rooms, allocate rooms, and track vacant and occupied beds.

The main application is developed using the C programming language, applying fundamental programming concepts such as arrays, structures, functions, searching, sorting, pointers, and file handling.

## 🎯 Objectives

- Maintain student registration details.
- Organize hostel rooms across different blocks and floors.
- Allocate rooms to registered students.
- Search and sort student records.
- Display vacant rooms and occupancy status.
- Cancel existing room allocations.
- Delete student entries when permitted.
- Store hostel information using file handling.
- Visualize room availability through a web dashboard.

## 🛠️ Technologies Used

| Technology | Purpose |
|---|---|
| C | Main hostel management application |
| Python | Dashboard backend |
| Flask | Web server and API |
| HTML | Dashboard structure |
| CSS | Dashboard styling |
| JavaScript | Dynamic room visualization |
| GCC | C program compilation |

## 🏢 Hostel Structure

The hostel is organized into four blocks:

| Block | Hostel Category | Theme |
|---|---|---|
| A | Boys | Sky Blue |
| B | Boys | Sky Blue |
| C | Girls | Baby Pink |
| D | Girls | Baby Pink |

Each block contains:
- 3 floors
- 20 rooms per floor
- 4 beds per room

**Total capacity:**
- 4 Blocks
- 12 Floors
- 240 Rooms
- 960 Beds

## ⚙️ Main Features

### 1. Student Management
- Register new students.
- Display registered students.
- Search students using registration numbers.
- Sort student records alphabetically by name.
- Delete student entries after checking active room allocations.

### 2. Room Management
- Initialize hostel rooms.
- Display room details.
- View vacant rooms.
- Maintain room capacity and occupancy.
- Identify AC and non-AC rooms.

### 3. Room Allocation
- Allocate rooms to registered students.
- Check room availability before allocation.
- Prevent duplicate active allocations.
- Cancel existing room allocations.
- Display allocation records.

### 4. File Handling
- Store student, room, and allocation information in `hostel.dat`.
- Load saved information when the application starts.
- Save changes to maintain records between executions.

### 5. Read-Only Web Dashboard

The project includes a visual dashboard built using HTML, CSS, JavaScript, and Python Flask.

Dashboard features:
- Separate visual cards for all four hostel blocks.
- Floor-wise room display.
- Individual bed icons.
- Green indicates vacant beds.
- Red indicates occupied beds.
- Total room, vacant bed, and occupied bed summaries.
- Automatic refresh every 5 seconds.

**Note:** The dashboard is read-only. Student registration, room allocation, cancellation, and deletion are performed through the main C application.

## 🧠 C Programming Concepts Applied

| Concept | Application |
|---|---|
| Arrays | Storing student and room information |
| Multidimensional Arrays | Organizing rooms by block, floor, and room |
| Structures | Representing students, rooms, and allocations |
| Functions | Dividing the application into modules |
| Searching | Finding students and room records |
| Bubble Sort | Sorting students by name |
| Pointers | Accessing and locating room records |
| File Handling | Saving and retrieving hostel data |

## 📂 Project Structure

```text
HostelBooking/
│
├── main.c
├── hostel.h
│
├── member1_student.c
├── member1_student.h
│
├── member2_room.c
├── member2_room.h
│
├── member3_allocation.c
├── member3_allocation.h
│
├── app.py
├── dashboard.html
│
├── .gitignore
└── README.md
```

Generated files such as `hostel.dat`, `dashboard.json`, and `hostel.exe` are created locally when running the application.

## 🚀 How to Run the Project

### Prerequisites

- GCC compiler
- Python 3
- Flask
- Visual Studio Code (recommended)

### Step 1: Clone the Repository

```bash
git clone https://github.com/jjoannapriscilla-tech/HostelBooking.git
```

### Step 2: Open the Project Folder

```bash
cd HostelBooking
```

### Step 3: Compile the C Program

```bash
gcc *.c -o hostel.exe
```

### Step 4: Run the C Application

```bash
./hostel.exe
```

On Windows PowerShell, use:

```powershell
.\hostel.exe
```

### Step 5: Install Flask

Open another terminal:

```bash
py -m pip install flask
```

### Step 6: Start the Dashboard

```bash
py app.py
```

### Step 7: Open the Dashboard

Visit the following address in your browser:

```text
http://127.0.0.1:5000
```

**Important:** Initialize the hostel rooms through the C application if they have not already been initialized. Save and exit the C application to generate the dashboard data.

## 👥 Project Team

This project is developed collaboratively by three team members.

- **Member 1:** Student Management
- **Member 2:** Room Management
- **Member 3:** Room Allocation and File Handling

## 📈 Expected
Efficient management of student records.

Organized hostel room allocation.

Accurate tracking of vacant and occupied beds.

Reduced manual record-keeping.

Improved visualization of hostel occupancy.

Practical application of fundamental C programming concepts.

🔮 Future Enhancements

Student details editing.

CSV-based student data import.

Interactive room allocation through the dashboard.

Individual bed assignment and tracking.

Login and administrator access.

📝 Conclusion

The College Hostel Room Allocation System demonstrates how fundamental C programming concepts can be applied to solve a practical management problem. By combining modular programming, structures, arrays, searching, sorting, and file handling, the system provides an organized approach to hostel administration.

The additional read-only dashboard improves the presentation of room availability and occupancy, making the system easier to understand and monitor.

Project: College Hostel Room Allocation System
Programming Language: C
Dashboard: Python Flask, HTML, CSS and JavaScript
Repository: HostelBooking
