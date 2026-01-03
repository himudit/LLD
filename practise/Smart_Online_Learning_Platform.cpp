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

    friend class ProgrammingCBuilder;
    friend class DesignCBuilder;
};
class ProgrammingCourse : public Course
{
public:
    void showDetails()
    {
        cout << "Welcome to Programming Course " + title + " made by " + instructor + " duration of " + duration + " at " << pricing << endl;
    }
};
class DesignCourse : public Course
{
    void showDetails()
    {
        cout << "Welcome to Design Course " + title + " made by " + instructor + " duration of " + duration + " at " << pricing << endl;
    }
};
class Builder
{
protected:
    Course *course;

public:
    virtual void reset() = 0;
    virtual Builder *setTitle(string t) = 0;
    virtual Builder *setInstructor(string i) = 0;
    virtual Builder *setDuration(string d) = 0;
    virtual Builder *setPricing(int p) = 0;

    virtual Course *Build() = 0;
};
class ProgrammingCBuilder : public Builder
{
public:
    ProgrammingCBuilder() { reset(); }

    void reset() override
    {
        course = new ProgrammingCourse();
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
        Course *res = course;
        course = nullptr;
        return res;
    }
};
class DesignCBuilder : public Builder
{
public:
    DesignCBuilder() { reset(); }

    void reset() override
    {
        course = new DesignCourse();
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
        Course *res = course;
        course = nullptr;
        return res;
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
    Builder *builder = new DesignCBuilder();
    Course *UI_UX = builder
                        ->setTitle("UI/UX Mastery")
                        ->setInstructor("Mudit")
                        ->setDuration("3 hours")
                        ->setPricing(3000)
                        ->Build();
    UI_UX->showDetails();
}