import sys
import itertools
import subprocess

def run_push_swap(numbers):
    """Run push_swap and return the number of instructions."""
    # Convert list of ints to list of strings for the command
    args = [str(n) for n in numbers]
    try:
        # Run ./push_swap and capture stdout
        result = subprocess.run(['./a.out'] + args, capture_output=True, text=True)
        # Split output by lines and count them (filtering out empty lines)
        lines = [line for line in result.stdout.split('\n') if line.strip()]
        return len(lines)
    except Exception as e:
        return f"Error: {e}"

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print(f"Usage: python {sys.argv[0]} num1 [num2 ... numN]")
        sys.exit(1)

    try:
        numbers = [int(arg) for arg in sys.argv[1:]]
        permutations = list(itertools.permutations(numbers))
        
        results_file = "test_results.txt"
        max_moves = 0
        worst_perm = ""

        with open(results_file, "w") as f:
            f.write(f"Push_swap test results for {tuple(numbers)}\n")
            f.write("-" * 40 + "\n")
            
            for perm in permutations:
                count = run_push_swap(perm)
                f.write(f"Perm: {perm} -> Moves: {count}\n")
                
                # Keep track of the worst case
                if isinstance(count, int) and count > max_moves:
                    max_moves = count
                    worst_perm = perm

            f.write("-" * 40 + "\n")
            f.write(f"Total permutations tested: {len(permutations)}\n")
            f.write(f"Worst case: {worst_perm} with {max_moves} moves.\n")

        print(f"Testing complete! Results saved to {results_file}")
        print(f"Worst case found: {max_moves} moves.")
    
    except ValueError:
        print("Error: All arguments must be valid integers.")
