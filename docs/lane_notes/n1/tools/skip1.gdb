set pagination off
set confirm off
set $n = 0
break fill_simple_delay_slots if non_jumps_p == 1
commands
silent
set $n = $n + 1
if $n == 1
  return
end
continue
end
run
