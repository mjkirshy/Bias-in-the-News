from django.urls import path
from . import views

## PATH Arguments
## 1. Route: the string that contains the url pattern
## 2. View: calls the specified views function
## 3. Name: naming the url allows you to use it all over your site 
## WATCH WHAT YOU NAME YOUR VIEWS/ROUTES

app_name = 'fake_news'
urlpatterns = [
    path('', views.index, name='index'),
    #path('formpage/', views.from_name_view, name='form_page')
]