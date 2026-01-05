Here’s a **map you can follow like a checklist** (and you won’t get lost). It’s ordered so that every next step depends only on what you already built.

---

## Push_swap Roadmap (the order that actually works)

### 0) Skeleton setup (10 min)

- Create folders + empty files
- Makefile builds **libft** and your project (even if sources are empty)
- `push_swap.h` compiles

✅ Goal: `make` works and produces `push_swap` (even if it does nothing yet)

---

## 1) Core stack layer (must be perfect)

**Files:** `stack/stack_init.c`, `stack/stack_utils.c`

Implement:

- `stack_new`    
- `stack_add_front`
- `stack_add_back`
- `stack_clear`
- `stack_size`
- `is_sorted`  
    (+ strongly recommended: `stack_last`, `stack_min`, `stack_max`, `stack_index_of`)


✅ Goal: you can build a stack in memory, print it in a debug test, free it with no leaks.

---

## 2) Parsing + errors (no algorithms yet)

**Files:** `main.c`, `error.c` (+ `parse_arguments` file if you want)

Implement:

- Parse flags: `--simple/--medium/--complex/--adaptive/--bench`    
- Parse numbers:
    - handle `"1 2 3"` inside one arg
    - handle `+42`, `-42`
    - reject non-integers
    - reject overflow/underflow
- `has_duplicates`
- On any error: print `"Error\n"` to `stderr` and exit

✅ Goal:

- `./push_swap` prints nothing
- `./push_swap 1 2 3` outputs nothing (already sorted)
- `./push_swap 1 a 3` → `Error`


---

## 3) Operations engine (the heart)

**Files:** `operations/swap.c`, `push.c`, `rotate.c`, `reverse_rotate.c`

Build operations as **two-layer design**:

### Layer A: silent “exec” functions (no printing)

- `sa_exec(t_stack **a)`    
- `pb_exec(t_stack **a, t_stack **b)`

- etc.
    

### Layer B: public ones (print + stats + call exec)

- `sa(t_data *data)` prints `"sa\n"` and increments stats then calls exec.
    

✅ Goal: operations are correct and reusable by both:

- `push_swap` (prints)
    
- `checker` (silent)
    

---

## 4) Disorder metric (mandatory requirement)

**File:** `stack/disorder.c`

Implement:

- `compute_disorder(stack_a)` exactly based on inversions:
    
    - sorted → 0
        
    - reversed → ~1
        

✅ Goal: you can compute it **before any moves** and store it in `data.stats.disorder`.

---

## 5) Strategy selection (dispatcher)

**File:** `main.c` or `algorithms/adaptive.c`

Write ONE dispatcher:

- if already sorted → return
    
- else:
    
    - if forced `--simple` → `sort_simple`
        
    - else if forced `--medium` → `sort_medium`
        
    - else if forced `--complex` → `sort_complex`
        
    - else → `sort_adaptive` (default)
        

✅ Goal: correct strategy chosen always.

---

## 6) Algorithms (in this order)

### 6.1 Simple (small sizes first)

**File:** `algorithms/simple.c`

- Make it perfect for: 2, 3, 4, 5 (and can scale to n²)
    

✅ Goal: small inputs are clean and minimal-ish.

### 6.2 Complex (easiest “big input” win)

**File:** `algorithms/complex.c`

- Implement radix or another n log n stack-friendly approach
    

✅ Goal: 100/500 random numbers work with decent counts.

### 6.3 Medium (chunk √n)

**File:** `algorithms/medium.c`

- Do chunk/bucket with ~√n chunks
    

✅ Goal: satisfies subject’s “medium” constraint.

### 6.4 Adaptive (glue logic)

**File:** `algorithms/adaptive.c`

- disorder < 0.2 → use “almost sorted” linear-ish approach
    
- 0.2–0.5 → medium
    
- > =0.5 → complex
    

✅ Goal: matches the subject thresholds.

---

## 7) Benchmark mode

**File:** `benchmark/benchmark.c`

If `--bench`:

- Print to `stderr`:
    
    - disorder % (2 decimals)
        
    - strategy name + complexity
        
    - total ops
        
    - each op count
        

✅ Goal: benchmark output never pollutes stdout operations.

---

## 8) Bonus checker (last)

**Files:** `bonus/checker_bonus.c`

- Reads operations line by line from stdin
    
- Executes silent ops
    
- Prints `OK` or `KO`
    

✅ Goal: `./push_swap ... | ./checker ...` works.

---

# The exact “start here” for you

Start with **Phase 1 + Phase 2**:

✅ **Today’s target**:

1. Implement stack functions
    
2. Implement parsing + errors
    
3. Make sure `./push_swap 3 2 1` builds the stack and exits (no sorting yet)
    

If you want, paste your current `stack_init.c` (even if empty) and I’ll guide you line-by-line in the exact order above.