int search(FILE* fp, int id){

  char buffer[200];
  struct studentData student = {0, " ", " ", 0, 0, 0, 0.0};

  int line = 0;
  int counter = 0;
  while(fgets(buffer, sizeof(buffer), fp) != NULL){

    sscanf(buffer, "%d %s %s %d %d %d %lf", &student.id, student.name, student.surname,
                                            &student.grade1, &student.grade2, &student.grade3, &student.average);
    counter++;
    if(student.id == id){
      line = counter;
    }
  }
  return line;
} //end of search function.
