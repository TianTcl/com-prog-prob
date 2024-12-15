# sudo du -h / | sort -rh | head -n 25
echo Before:
du -h /home/tiantcl/cafe_grader/judge/result | sort -rh | head -n 10
rm -f /home/tiantcl/cafe_grader/judge/result/*/*/*/test-result/*.out
rm -f /home/tiantcl/cafe_grader/judge/result/*/*/*/test-result/*/output.txt
echo After:
du -h /home/tiantcl/cafe_grader/judge/result | sort -rh | head -n 5