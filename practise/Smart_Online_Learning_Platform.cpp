#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

class Course
{
protected:
    string title = "Default";
    string instructor = "Default";
    string duration = "Default";
    int pricing = 0;

public:
    virtual void showDetails() = 0;
    virtual Course *clone() = 0;

    friend class ProgrammingCBuilder;
    friend class DesignCBuilder;
};
class CourseTemplate : public Course
{
public:
    CourseTemplate()
    {
        title = "Default";
        instructor = "Default";
        duration = "Default";
        pricing = 0;
    }
    CourseTemplate(const CourseTemplate &other)
    {
        title = other.title;
        instructor = other.instructor;
        duration = other.duration;
        pricing = other.pricing;
    }
    Course *clone()
    {
        return new CourseTemplate(*this);
    }
    void showDetails()
    {
        cout << "Welcome to Course " + title + " made by " + instructor + " duration of " + duration + " at " << pricing << endl;
    }
};
class ProgrammingCourse : public Course
{
public:
    void showDetails()
    {
        cout << "Welcome to Programming Course " + title + " made by " + instructor + " duration of " + duration + " at " << pricing << endl;
    }
    Course *clone() override
    {
        return new ProgrammingCourse(*this);
    }
};
class DesignCourse : public Course
{
    void showDetails()
    {
        cout << "Welcome to Design Course " + title + " made by " + instructor + " duration of " + duration + " at " << pricing << endl;
    }
    Course *clone() override
    {
        return new DesignCourse(*this);
    }
};
class Builder
{
protected:
    Course *course;

public:
    virtual void setCourse(Course *c) = 0;
    virtual Builder *setTitle(string t) = 0;
    virtual Builder *setInstructor(string i) = 0;
    virtual Builder *setDuration(string d) = 0;
    virtual Builder *setPricing(int p) = 0;

    virtual Course *Build() = 0;
};
class ProgrammingCBuilder : public Builder
{
public:
    ProgrammingCBuilder() {}

    void setCourse(Course *c) override
    {
        course = c; // attach existing prototype-cloned course
    }

    Builder *setTitle(string t) override
    {
        course->title = t;
        return this;
    }
    Builder *setInstructor(string i) override
    {
        course->instructor = i;
        return this;
    }
    Builder *setDuration(string d) override
    {
        course->duration = d;
        return this;
    }
    Builder *setPricing(int p) override
    {
        course->pricing = p;
        return this;
    }
    Course *Build()
    {
        return course;
    }
};
class DesignCBuilder : public Builder
{
public:
    DesignCBuilder() {}

    void setCourse(Course *c) override
    {
        course = c; // attach existing prototype-cloned course
    }

    Builder *setTitle(string t) override
    {
        course->title = t;
        return this;
    }
    Builder *setInstructor(string i) override
    {
        course->instructor = i;
        return this;
    }
    Builder *setDuration(string d) override
    {
        course->duration = d;
        return this;
    }
    Builder *setPricing(int p) override
    {
        course->pricing = p;
        return this;
    }
    Course *Build()
    {
        return course;
    }
};
class courseFactory
{
public:
    virtual Course *createCourse() = 0;
};
class ProgrammingCourseFactory : public courseFactory
{
public:
    Course *createCourse()
    {
        return new ProgrammingCourse;
    }
};
class DesignCourseFactory : public courseFactory
{
public:
    Course *createCourse()
    {
        return new DesignCourse;
    }
};
int main()
{
    courseFactory *cf = new ProgrammingCourseFactory();
    Course *JS = cf->createCourse();
    JS->showDetails();
    Builder *Dbuilder = new DesignCBuilder();
    Dbuilder->setCourse(JS);
    Dbuilder
        ->setTitle("JS Mastery")
        ->setInstructor("Mudit")
        ->setDuration("3 hours")
        ->setPricing(3000)
        ->Build();
    JS->showDetails();

    Course *programmingTemplate = new CourseTemplate();
    Course *baseCourse = programmingTemplate->clone();
    baseCourse->showDetails();

    Builder *Pbuilder = new ProgrammingCBuilder();
    Pbuilder->setCourse(baseCourse);
    Pbuilder
        ->setTitle("C++ Mastery")
        ->setInstructor("Aman Gupta")
        ->setDuration("2.5 hours")
        ->setPricing(1999)
        ->Build();
    baseCourse->showDetails();
}