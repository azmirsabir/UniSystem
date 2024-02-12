cmake_minimum_required(VERSION 3.24)
project(APTAssignment)

set(CMAKE_CXX_STANDARD 17)

#add_executable(APTAssignment main.cpp Models/College.cpp Models/Department.cpp Models/Student.cpp Models/Module.cpp Models/Helper/ExcelReader.cpp Models/Helper/DataModel.cpp Models/Helper/Temp.cpp Models/StudentAssessment.cpp Models/DepartmentModule.cpp Models/College.h Models/Helper/DataModel.h Models/Helper/ExcelReader.h Models/Department.h Models/DepartmentModule.h Models/Module.h Models/Student.h Models/StudentAssessment.h)
add_executable(APTAssignment main.cpp Models/College.cpp Models/Department.cpp Models/Student.cpp Models/Module.cpp Models/Helper/DataModel.cpp Models/StudentAssessment.cpp Models/DepartmentModule.cpp Models/Helper/ExcelReader.cpp Models/Helper/CMD.cpp Models/College.h Models/Department.h Models/DepartmentModule.h Models/Module.h Models/Student.h Models/StudentAssessment.h)
