
# PlanAhead Launch Script for Post-Synthesis pin planning, created by Project Navigator

create_project -name LV3_vhdl -dir "D:/DRS/LV3_Milicevic_Istvanic/ISE/LV3_vhdl/planAhead_run_5" -part xc6slx16csg324-3
set_property design_mode GateLvl [get_property srcset [current_run -impl]]
set_property edif_top_file "D:/DRS/LV3_Milicevic_Istvanic/ISE/LV3_vhdl/ledBTNU.ngc" [ get_property srcset [ current_run ] ]
add_files -norecurse { {D:/DRS/LV3_Milicevic_Istvanic/ISE/LV3_vhdl} }
set_param project.pinAheadLayout  yes
set_property target_constrs_file "ledBTNU.ucf" [current_fileset -constrset]
add_files [list {ledBTNU.ucf}] -fileset [get_property constrset [current_run]]
link_design
