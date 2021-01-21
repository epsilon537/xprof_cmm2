'XPROF.INC
'---------
'This simple module periodically logs TRACE data to the serial port using a timer interrupt.
'Obviously OPTION CONSOLE should be set to either SERIAL or BOTH.
'To be used in conjunction with xprof.py on the host side.
'Author: Epsilon.

CONST XPROF_VERSION$ = "0.1"

'Start xprof timer tick, i.e. start profiling. 
'Pass in timer_id to use and timer period in ms.
SUB xprof_start(timer_id%, period_ms%)
  SETTICK period_ms%, xprof_isr, timer_id%
END SUB

'Stop profiling.
SUB xprof_stop
  SETTICK 0, xprof_isr, XPROF_TIMER%
END SUB

'The timer interrupt service routine.
SUB xprof_isr
  PRINT:PRINT "P:";
  TRACE LIST 6
  PRINT
END SUB

