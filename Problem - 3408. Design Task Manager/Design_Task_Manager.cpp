#include <bits/stdc++.h>
using namespace std;

/*
  -------------------- INTUITION & DESIGN --------------------
  We want to build a TaskManager system that can:

     - add(userId, taskId, priority)
     - edit(taskId, newPriority)
     - rmv(taskId)
     - execTop() -> returns userId of highest-priority task and removes it

  To support this efficiently, we need to:
     - Quickly find a task's current priority and userId by taskId
     - Quickly get and remove the highest-priority task

  So we use:
     - unordered_map<int,int> taskinfo:    taskId -> userId
     - unordered_map<int,int> userinfo:    taskId -> priority
     - set<pair<int,int>> s: sorted by (priority, taskId)

  WHY `set`? 
     - It stores (priority, taskId) pairs in ascending order automatically.
     - The highest-priority task will be at the *end* of the set.
     - We can erase and insert in O(log n) time, which is fine for these operations.

  This `set` is effectively working as a **balanced BST-based priority queue**
  where we can also erase arbitrary elements (unlike normal `priority_queue`).

  -------------------------------------------------------------
*/

class TaskManager {
public:
    // taskId -> userId
    unordered_map<int,int> taskinfo;

    // taskId -> priority
    unordered_map<int,int> userinfo;

    // stores (priority, taskId) sorted ascending by priority first, then taskId
    set<pair<int,int>> s;

    // Constructor: build initial tasks from a list of [userId, taskId, priority]
    TaskManager(vector<vector<int>>& tasks) {
        for (auto &i : tasks) {
            int uid = i[0];
            int tid = i[1];
            int p   = i[2];
            add(uid, tid, p);  // use our add() to insert them
        }
    }
    
    // Add a new task into the system
    void add(int userId, int taskId, int priority) {
        taskinfo[taskId] = userId;       // record who owns this task
        userinfo[taskId] = priority;     // record priority
        s.insert({priority, taskId});    // insert in set (priority queue-like structure)
    }
    
    // Edit the priority of an existing task
    void edit(int taskId, int newPriority) {
        int oldPriority = userinfo[taskId];       // find old priority
        s.erase({oldPriority, taskId});           // remove old pair from set
        userinfo[taskId] = newPriority;            // update new priority
        s.insert({newPriority, taskId});           // insert new pair in set
    }
    
    // Remove a task completely from the system
    void rmv(int taskId) {
        int priority = userinfo[taskId];       // get its priority
        s.erase({priority, taskId});           // remove from set
        userinfo.erase(taskId);                // remove from maps
        taskinfo.erase(taskId);
    }
    
    // Execute the highest priority task and return its userId
    int execTop() {
        if (s.empty()) return -1;    // no task available

        // get iterator to last element (highest priority)
        auto it = prev(s.end());
        int taskId = it->second;
        int userId = taskinfo[taskId];

        // remove it from all data structures
        s.erase(it);
        userinfo.erase(taskId);
        taskinfo.erase(taskId);

        return userId;   // return user who owned the top-priority task
    }

};

/*
--------------------------------------------
TIME COMPLEXITY ANALYSIS
--------------------------------------------
- add(): O(log n) due to set insertion
- edit(): O(log n) erase + O(log n) insert
- rmv(): O(log n) erase
- execTop(): O(log n) erase of top element
All map operations are O(1) average.

--------------------------------------------
WHY NOT USE priority_queue?
--------------------------------------------
priority_queue can't remove or update arbitrary elements efficiently.
We need to be able to:
   - remove a specific task
   - update its priority
A set supports erase() of any element in O(log n),
which makes it better for this problem.

--------------------------------------------
USAGE EXAMPLE
--------------------------------------------
TaskManager* obj = new TaskManager(tasks);
obj->add(userId, taskId, priority);
obj->edit(taskId, newPriority);
obj->rmv(taskId);
int topUser = obj->execTop();
--------------------------------------------
*/
